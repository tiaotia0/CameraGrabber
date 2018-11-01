#ifndef _CV_CALIBRATION_H
#define _CV_CALIBRATION_H
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"

using std::vector;
struct SingleCalibrateResult
{
	cv::Mat m_CameraMatrix; /* 摄像机内参数矩阵 */
	cv::Mat m_DistCoeffs; /* 摄像机的5个畸变系数：k1,k2,p1,p2,k3 */
	vector<double> m_Errorvec; /* 每幅图像的标定误差 */
	vector<cv::Mat> m_TvecsMat;  /* 每幅图像的旋转向量 */	//可转换为旋转矩阵：Rodrigues(m_TvecsMat[i], rotation_matrix);
	vector<cv::Mat> m_RvecsMat; /* 每幅图像的平移向量 */
};

struct DualCalibrateResult
{
	SingleCalibrateResult m_LeftCalibrateResult, m_RightCalibrateResult;
	double m_RMS_error;
	cv::Mat R, T, E, F; //R 旋转矢量 T平移矢量 E本征矩阵 F基础矩阵
};
class SingleCalibrator
{
public:
	//目前该构造函数先只有方格棋盘格标定
	SingleCalibrator(size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height,size_t real_square_size,size_t calibration_amount);

	bool SingleCalibrate(void * img_ptr, cv::Mat &img_to_show);
	SingleCalibrateResult GetSingleCalibrateResult();
private:
    SingleCalibrator() {}
	size_t m_RemainPicsToCalibrate ;
	cv::Size m_ImageSize, /* 图像的尺寸 */
		m_BoardSize;	/* 标定板上每行、列的角点数 */
	cv::Size m_SquareSize;  /* 实际的标定板上每个棋盘格的大小 */
	std::vector<std::vector<cv::Point2f>> m_ImageCorners_seq;	/* 保存检测到的所有角点(亚像素点) */
	vector<vector<cv::Point3f>> m_RealObjectPoints_of_AllImages; /* 保存所有图像上的标定板上角点的三维坐标（定值） */
	cv::Mat m_CameraMatrix ; /* 摄像机内参数矩阵 */
	cv::Mat m_DistCoeffs ; /* 摄像机的5个畸变系数：k1,k2,p1,p2,k3 */
	vector<cv::Mat> m_TvecsMat;  /* 每幅图像的旋转向量 */
	vector<cv::Mat> m_RvecsMat; /* 每幅图像的平移向量 */
	vector<double> m_Errorvec; /* 每幅图像的标定误差 */
	
	void ErrorCaculate();
	friend class DualCalibrator;
};

class DualCalibrator
{
public:
	DualCalibrator(size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height, size_t real_square_size, size_t calibration_amount):
		m_Left(image_width,image_height,board_corner_width, board_corner_height, real_square_size, calibration_amount),
		m_Right(image_width, image_height, board_corner_width, board_corner_height, real_square_size, calibration_amount){}
	
	bool DualCalibrate(void * left_img_ptr, cv::Mat &left_img_to_show, void * right_img_ptr, cv::Mat &right_img_to_show);
	DualCalibrateResult GetDualCalibrateResult();
private:
    DualCalibrator() {}
    ~DualCalibrator() {}
	SingleCalibrator m_Left, m_Right;
	cv::Mat R, T, E, F; //R旋转矢量 T平移矢量 E本征矩阵 F基础矩阵
	double m_RMS_error = -1;
};
#endif // !_CV_CALIBRATION_H


