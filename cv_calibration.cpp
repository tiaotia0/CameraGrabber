#include"cv_calibration.h"

BaseCalibrator::BaseCalibrator(size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height, size_t real_square_size, size_t calibration_pic_amount, CalibrationBoardType cali_board_type)
{
	m_CalibrationBoardType = cali_board_type;
	m_ImageSize = cv::Size(image_width, image_height);
	m_BoardSize = cv::Size(board_corner_width, board_corner_height);
	m_SquareSize = cv::Size(real_square_size, real_square_size);
	m_CameraMatrix = cv::Mat(3, 3, CV_32FC1, cv::Scalar::all(0));
	m_DistCoeffs = cv::Mat(1, 5, CV_32FC1, cv::Scalar::all(0));
	m_RemainPicsToCalibrate = calibration_pic_amount;
	m_TotalPicsToCalibrate = calibration_pic_amount;

	m_ImageCorners_seq = std::vector<std::vector<cv::Point2f>>(calibration_pic_amount, std::vector<cv::Point2f>(board_corner_width*board_corner_height));
	m_RealObjectPoints_of_AllImages = std::vector<vector<cv::Point3f>>(calibration_pic_amount, std::vector<cv::Point3f>(board_corner_width*board_corner_height));
	m_TvecsMat = vector<cv::Mat>(calibration_pic_amount);
	m_RvecsMat = vector<cv::Mat>(calibration_pic_amount);
	/* ��ʼ��(ÿһ��ͼ)�궨���Ͻǵ����ά����(ע����Բ�뷽�����̸�����) */
	for (size_t cnt = 0; cnt < m_RemainPicsToCalibrate; cnt++)
	{
		vector<cv::Point3f> tempPointSet;
		for (int i = 0; i < m_BoardSize.height; i++)
		{
			for (int j = 0; j < m_BoardSize.width; j++)
			{
				/* ����궨�������������ϵ��z=0��ƽ���� */
				tempPointSet.push_back(cv::Point3f(float(j * m_SquareSize.width), float(i * m_SquareSize.height), 0));
			}
		}
		m_RealObjectPoints_of_AllImages[cnt] = tempPointSet;
	}
}

int BaseCalibrator::Calibrate(void * img_ptr, cv::Mat &img_to_show)
{
	//����ֵ��-1���ǵ�ʶ����󣬵�ǰͼ�񲻺ϸ�������ѡȡ
	//0~N��ʣ��ı궨��ͼ����Ŀ
	if (m_RemainPicsToCalibrate == 0) return 0; //�궨�ѽ���
	cv::Mat img(m_ImageSize.height, m_ImageSize.width, CV_8UC1, (unsigned char *)img_ptr);
	std::vector<cv::Point2f> image_points_tmp;
	image_points_tmp.resize(m_BoardSize.width*m_BoardSize.height);

	switch (m_CalibrationBoardType)
	{
	case CircleGrid:
		if (0 == findCirclesGrid(img, m_BoardSize, image_points_tmp))
		{
			return -1;  //�Ҳ����ǵ�
		}
		break;
	case ChessBorad:
		if (0==findChessboardCorners(img, m_BoardSize, image_points_tmp))
		{
			return -1;  //�Ҳ����ǵ�
		}
		else
		{
			/* �����ؾ�ȷ�� */
			find4QuadCornerSubpix(img, image_points_tmp, m_BoardSize); //�Դ���ȡ�Ľǵ���о�ȷ��
			//cornerSubPix(view_gray,image_points_buf,Size(5,5),Size(-1,-1),TermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER,30,0.1));
		}
		break;
	default:
		return -1;
		break;
	}
	m_ImageCorners_seq[m_TotalPicsToCalibrate - m_RemainPicsToCalibrate] = image_points_tmp;	 //���������ؽǵ�
	/* ��ͼ������ʾ�ǵ�λ�� */
	//��ͨ��ת3ͨ������ʾ��ɫʶ��ǵ�
	cv::Mat three_channel = cv::Mat::zeros(img.rows,img.cols, CV_8UC3); 
	vector<cv::Mat> channels = { img ,img ,img }; 
	merge(channels, three_channel);
	drawChessboardCorners(three_channel, m_BoardSize, image_points_tmp, true); //������ͼƬ�б�ǽǵ�
	img_to_show = three_channel;

	m_RemainPicsToCalibrate = m_RemainPicsToCalibrate > 0 ? m_RemainPicsToCalibrate - 1 : 0;
	if (m_RemainPicsToCalibrate == 0)
	{
		calibrateCamera(m_RealObjectPoints_of_AllImages, m_ImageCorners_seq, m_ImageSize, m_CameraMatrix, m_DistCoeffs, m_RvecsMat, m_TvecsMat, 0);
		ErrorCaculate();
	}
	return m_RemainPicsToCalibrate;
}

void BaseCalibrator::ErrorCaculate()
{
	m_Errorvec.clear();
	vector<cv::Point2f> image_corners2d_new; /* �������¼���õ���ͶӰ�� */
	image_corners2d_new.resize(m_BoardSize.width*m_BoardSize.height);
	int totalPoints = 0;
	double totalErr = 0;
	for (size_t i = 0; i < m_RealObjectPoints_of_AllImages.size(); i++)
	{
		/* ͨ���õ������������������Կռ����ά���������ͶӰ���㣬�õ��µ�ͶӰ�� */
		projectPoints(m_RealObjectPoints_of_AllImages[i], m_RvecsMat[i], m_TvecsMat[i], m_CameraMatrix, m_DistCoeffs, image_corners2d_new);
		/* �����µ�ͶӰ��;ɵ�ͶӰ��֮������*/
		double err = cv::norm(cv::Mat(m_ImageCorners_seq[i]), cv::Mat(image_corners2d_new), cv::NORM_L2);
		int n = (int)m_RealObjectPoints_of_AllImages[i].size();
		m_Errorvec.push_back((float)std::sqrt(err*err / n));
		totalErr += err * err;
		totalPoints += n;
	}
	m_totalErr = std::sqrt(totalErr / totalPoints);
}

BaseCalibrateResult BaseCalibrator::GetBaseCalibrateResult()
{
	BaseCalibrateResult result;
	if (m_RemainPicsToCalibrate != 0) return result;
	result.m_CameraMatrix = m_CameraMatrix;
	result.m_DistCoeffs = m_DistCoeffs;
	result.m_Errorvec = m_Errorvec;
	result.m_RvecsMat = m_RvecsMat;
	result.m_TvecsMat = m_TvecsMat;
	result.m_TotalErr = m_totalErr;
	return result;
}

CameraCalibrator::CameraCalibrator(bool left_camera, bool right_camera, size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height, size_t real_square_size, size_t calibration_pic_amount, CalibrationBoardType cali_board_type)
{
	if (left_camera&&right_camera)
	{
		m_Left = new BaseCalibrator(image_width, image_height, board_corner_width, board_corner_height, real_square_size, calibration_pic_amount, cali_board_type);
		m_Right = new BaseCalibrator(image_width, image_height, board_corner_width, board_corner_height, real_square_size, calibration_pic_amount, cali_board_type);
	}
	else if (left_camera && !right_camera)
	{
		m_Left = new BaseCalibrator(image_width, image_height, board_corner_width, board_corner_height, real_square_size, calibration_pic_amount, cali_board_type);
		m_Right = nullptr;
	}
	else if (!left_camera && right_camera)
	{
		m_Left = nullptr;
		m_Right = new BaseCalibrator(image_width, image_height, board_corner_width, board_corner_height, real_square_size, calibration_pic_amount, cali_board_type);
	}
}

CameraCalibrator::~CameraCalibrator()
{
	delete m_Left;
	delete m_Right; 
};

int CameraCalibrator::Calibrate(void * left_img_ptr, cv::Mat &left_img_to_show, void * right_img_ptr, cv::Mat &right_img_to_show)
{
	//����ֵ��-1���ǵ�ʶ����󣬵�ǰͼ�񲻺ϸ�������ѡȡ
	//0~N��ʣ��ı궨��ͼ����Ŀ
	if (m_Left&&m_Right)
	{
		if (m_Left->m_RemainPicsToCalibrate == 0 || m_Right->m_RemainPicsToCalibrate == 0) return 0; //�궨�ѽ���
		int tag_left = m_Left->Calibrate(left_img_ptr, left_img_to_show);
		int tag_right = m_Right->Calibrate(right_img_ptr, right_img_to_show);
		//״̬����
		if (tag_left < 0 || tag_right < 0)
		{
			if (tag_right < 0 && tag_left >=0)
			{
				//m_Left->m_ImageCorners_seq.pop_back();
				m_Left->m_RemainPicsToCalibrate += 1;
				m_Left->m_ImageCorners_seq[m_Left->m_TotalPicsToCalibrate - m_Left->m_RemainPicsToCalibrate]= std::vector<cv::Point2f>(m_Left->m_BoardSize.width*m_Left->m_BoardSize.height);
			}
			if (tag_left < 0 && tag_right >=0)
			{
				//m_Right->m_ImageCorners_seq.pop_back();
				m_Right->m_RemainPicsToCalibrate += 1;
				m_Right->m_ImageCorners_seq[m_Right->m_TotalPicsToCalibrate - m_Right->m_RemainPicsToCalibrate] = std::vector<cv::Point2f>(m_Right->m_BoardSize.width*m_Right->m_BoardSize.height);
			}
			return -1;
		}
		if (m_Left->m_RemainPicsToCalibrate == 0 && m_Right->m_RemainPicsToCalibrate == 0)
		{
			m_RMS_error = stereoCalibrate(m_Left->m_RealObjectPoints_of_AllImages, m_Left->m_ImageCorners_seq, m_Right->m_ImageCorners_seq,
				m_Left->m_CameraMatrix, m_Left->m_DistCoeffs,
				m_Right->m_CameraMatrix, m_Right->m_DistCoeffs,
				m_Left->m_ImageSize, R, T, E, F, cv::CALIB_USE_INTRINSIC_GUESS,
				cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, 1e-5));
		}
		return m_Left->m_RemainPicsToCalibrate;
	}
	else if(m_Left&&!m_Right)
	{
		auto a= m_Left->Calibrate(left_img_ptr, left_img_to_show);
		return a;
	}
	else if(!m_Left&&m_Right)
	{
		return m_Right->Calibrate(right_img_ptr, right_img_to_show);
	}
	return -1;
}

CameraCalibrateResult CameraCalibrator::GetCalibrateResult()
{
	CameraCalibrateResult result;
	if (m_Left&&m_Right)
	{
		if (m_Left->m_RemainPicsToCalibrate != 0 || m_Left->m_RemainPicsToCalibrate != 0) return result;
		result.m_LeftCalibrateResult = this->m_Left->GetBaseCalibrateResult();
		result.m_RightCalibrateResult = this->m_Right->GetBaseCalibrateResult();
		result.m_RMS_error = this->m_RMS_error;
		result.R = this->R;
		result.T = this->T;
		result.E = this->E;
		result.F = this->F;
		return result;
	}
	if (m_Left && !m_Right)
	{
		result.m_LeftCalibrateResult= this->m_Left->GetBaseCalibrateResult();
		return result;
	}
	if (!m_Left && m_Right)
	{
		result.m_RightCalibrateResult= this->m_Right->GetBaseCalibrateResult();
		return result;
	}
	return result;
}
