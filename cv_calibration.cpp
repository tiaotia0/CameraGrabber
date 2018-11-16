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
	/* 初始化(每一幅图)标定板上角点的三维坐标(注：仅圆与方的棋盘格适用) */
	for (size_t cnt = 0; cnt < m_RemainPicsToCalibrate; cnt++)
	{
		vector<cv::Point3f> tempPointSet;
		for (int i = 0; i < m_BoardSize.height; i++)
		{
			for (int j = 0; j < m_BoardSize.width; j++)
			{
				/* 假设标定板放在世界坐标系中z=0的平面上 */
				tempPointSet.push_back(cv::Point3f(float(j * m_SquareSize.width), float(i * m_SquareSize.height), 0));
			}
		}
		m_RealObjectPoints_of_AllImages.push_back(tempPointSet);
	}
}

int BaseCalibrator::Calibrate(void * img_ptr, cv::Mat &img_to_show)
{
	//返回值：-1，角点识别错误，当前图像不合格，需重新选取
	//0~N，剩余的标定的图像数目
	if (m_RemainPicsToCalibrate == 0) return 0; //标定已结束
	cv::Mat img(m_ImageSize.height, m_ImageSize.width, CV_8UC1, img_ptr);
	std::vector<cv::Point2f> image_points_tmp;
	switch (m_CalibrationBoardType)
	{
	case CircleGrid:
		if (0 == findCirclesGrid(img, m_BoardSize, image_points_tmp))
		{
			return -1;  //找不到角点
		}
		break;
	case ChessBorad:
		if (0 == findChessboardCorners(img, m_BoardSize, image_points_tmp))
		{
			return -1;  //找不到角点
		}
		else
		{
			/* 亚像素精确化 */
			find4QuadCornerSubpix(img, image_points_tmp, m_BoardSize); //对粗提取的角点进行精确化
			//cornerSubPix(view_gray,image_points_buf,Size(5,5),Size(-1,-1),TermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER,30,0.1));
		}
		break;
	default:
		return -1;
		break;
	}
	m_ImageCorners_seq.push_back(image_points_tmp);  //保存亚像素角点
			/* 在图像上显示角点位置 */
	drawChessboardCorners(img_to_show, m_BoardSize, image_points_tmp, true); //用于在图片中标记角点
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
	vector<cv::Point2f> image_corners2d_new; /* 保存重新计算得到的投影点 */
	int totalPoints = 0;
	double totalErr = 0;
	for (size_t i = 0; i < m_RealObjectPoints_of_AllImages.size(); i++)
	{
		/* 通过得到的摄像机内外参数，对空间的三维点进行重新投影计算，得到新的投影点 */
		projectPoints(m_RealObjectPoints_of_AllImages[i], m_RvecsMat[i], m_TvecsMat[i], m_CameraMatrix, m_DistCoeffs, image_corners2d_new);
		/* 计算新的投影点和旧的投影点之间的误差*/
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

int CameraCalibrator::Calibrate(void * left_img_ptr, cv::Mat &left_img_to_show, void * right_img_ptr, cv::Mat &right_img_to_show)
{
	//返回值：-1，角点识别错误，当前图像不合格，需重新选取
	//0~N，剩余的标定的图像数目
	if (m_Left&&m_Right)
	{
		if (m_Left->m_RemainPicsToCalibrate == 0 || m_Right->m_RemainPicsToCalibrate == 0) return 0; //标定已结束
		int tag_left = m_Left->Calibrate(left_img_ptr, left_img_to_show);
		int tag_right = m_Right->Calibrate(right_img_ptr, right_img_to_show);
		//状态回退
		if (tag_left < 0 || tag_right < 0)
		{
			if (tag_right < 0 && tag_left >=0)
			{
				m_Left->m_ImageCorners_seq.pop_back();
				m_Left->m_RemainPicsToCalibrate += 1;
			}
			if (tag_left < 0 && tag_right >=0)
			{
				m_Right->m_ImageCorners_seq.pop_back();
				m_Right->m_RemainPicsToCalibrate += 1;
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
		return m_Left->Calibrate(left_img_ptr, left_img_to_show);
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
