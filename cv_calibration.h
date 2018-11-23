#ifndef _CV_CALIBRATION_H
#define _CV_CALIBRATION_H
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"

using std::vector;
struct BaseCalibrateResult
{
	cv::Mat m_CameraMatrix; /* ������ڲ������� */
	cv::Mat m_DistCoeffs; /* �������5������ϵ����k1,k2,p1,p2,k3 */
	vector<double> m_Errorvec; /* ÿ��ͼ��ı궨��� */
	double m_TotalErr; /* �궨��� */
	vector<cv::Mat> m_TvecsMat;  /* ÿ��ͼ�����ת���� */	//��ת��Ϊ��ת����Rodrigues(m_TvecsMat[i], rotation_matrix);
	vector<cv::Mat> m_RvecsMat; /* ÿ��ͼ���ƽ������ */
};

struct CameraCalibrateResult
{
	BaseCalibrateResult m_LeftCalibrateResult, m_RightCalibrateResult;
	double m_RMS_error;
	cv::Mat R, T, E, F; //R ��תʸ�� Tƽ��ʸ�� E�������� F��������
};

enum CalibrationBoardType
{
	CircleGrid=0,
	ChessBorad = 1
};

class BaseCalibrator
{
	//Ŀǰ�ù��캯����ֻ�е���Բ�� �� �������̸�궨
friend class CameraCalibrator;
private:
	BaseCalibrator() {};
	BaseCalibrator(size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height, size_t real_square_size, size_t calibration_pic_amount, CalibrationBoardType cali_board_type);

	int Calibrate(void * img_ptr, cv::Mat &img_to_show);
	BaseCalibrateResult GetBaseCalibrateResult();
	CalibrationBoardType m_CalibrationBoardType;

	size_t m_RemainPicsToCalibrate ;
	cv::Size m_ImageSize, /* ͼ��ĳߴ� */
		m_BoardSize;	/* �궨����ÿ�С��еĽǵ��� */
	cv::Size m_SquareSize;  /* ʵ�ʵı궨����ÿ�����̸�Ĵ�С */
	std::vector<std::vector<cv::Point2f>> m_ImageCorners_seq;	/* �����⵽�����нǵ�(�����ص�) */
	vector<vector<cv::Point3f>> m_RealObjectPoints_of_AllImages; /* ��������ͼ���ϵı궨���Ͻǵ����ά���꣨��ֵ�� */
	cv::Mat m_CameraMatrix ; /* ������ڲ������� */
	cv::Mat m_DistCoeffs ; /* �������5������ϵ����k1,k2,p1,p2,k3 */
	vector<cv::Mat> m_TvecsMat;  /* ÿ��ͼ�����ת���� */
	vector<cv::Mat> m_RvecsMat; /* ÿ��ͼ���ƽ������ */
	vector<double> m_Errorvec; /* ÿ��ͼ��ı궨��� */
	double m_totalErr;
	void ErrorCaculate();
};

class CameraCalibrator
{
public:
	CameraCalibrator(bool left_camera, bool  right_camera, size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height, size_t real_square_size, size_t calibration_pic_amount, CalibrationBoardType cali_board_type);
	~CameraCalibrator();
	int Calibrate(void * left_img_ptr, cv::Mat &left_img_to_show, void * right_img_ptr, cv::Mat &right_img_to_show);
	CameraCalibrateResult GetCalibrateResult();
private:
	CameraCalibrator() {};
	BaseCalibrator *m_Left, *m_Right;
	cv::Mat R, T, E, F; //R��תʸ�� Tƽ��ʸ�� E�������� F��������
	double m_RMS_error = -1;
	CameraCalibrateResult m_CameraCalibrateResult;
};
#endif // !_CV_CALIBRATION_H


