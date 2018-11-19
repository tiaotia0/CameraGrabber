#ifndef IMAGEPROCESSCONTROLER_H
#define IMAGEPROCESSCONTROLER_H

#include "siliconboard.h"
#include "cv_calibration.h"
#include <QImage>
#include <Windows.h>
#include <assert.h>
#include <QVector>
#include <memory>
#include <qmutex.h>

class Gray8bitQImageCorlorTable {
public:
	static QVector<QRgb> vcolorTable;
	static bool IsConstructed;
	const QVector<QRgb>& GetGray8bitQImageCorlorTable();
};

class ImageDisplayControler : public QObject, public Base_ImageContrler
{
    Q_OBJECT

public:
	bool is_recording = false;
	volatile bool is_calibrating = false;
	bool is_playing = false;
	size_t picNr_toSave = 0;
	std::string m_FilePathToSave;

    ImageDisplayControler(ImageCaptureBoard & img_cap_board, size_t port_index) :Base_ImageContrler(img_cap_board, port_index) {}
    void HowToProcessImages(void *img_prt, size_t img_len) override;
signals:
	void sendCalibImage(void *img_ptr);
	void sendDisplayImage(QImage qImg);
};

class CameraCalibrateControler :public QObject, public CameraCalibrator
{
	Q_OBJECT

public:
	CameraCalibrateControler(size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height, size_t real_square_size, size_t calibration_pic_amount, CalibrationBoardType cali_board_type):
		CameraCalibrator(image_width, image_height, board_corner_width, board_corner_height, real_square_size, calibration_pic_amount, cali_board_type) ,
		m_img_width(image_width),m_img_height(image_height){}

	CameraCalibrateControler(void * no_left_cam, size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height, size_t real_square_size, size_t calibration_pic_amount, CalibrationBoardType cali_board_type) :
		CameraCalibrator(no_left_cam, image_width, image_height, board_corner_width, board_corner_height, real_square_size, calibration_pic_amount, cali_board_type),
		m_img_width(image_width), m_img_height(image_height) {}

	CameraCalibrateControler(size_t image_width, size_t image_height, size_t board_corner_width, size_t board_corner_height, size_t real_square_size, size_t calibration_pic_amount, CalibrationBoardType cali_board_type, void * no_right_cam) :
		CameraCalibrator(image_width, image_height, board_corner_width, board_corner_height, real_square_size, calibration_pic_amount, cali_board_type, no_right_cam),
		m_img_width(image_width), m_img_height(image_height) {}

	void * left_img_ptr = nullptr;
	void * right_img_ptr = nullptr;
	int m_img_width,
		m_img_height;
	QMutex calib_mtx;
	size_t calib_img_count;
	size_t camera_num = 0;

signals:
	void sendLeftCalibImage(QImage qimg);
	void sendRightCalibImage(QImage qimg);
	void sendCalibrateStatus(QVector<QString> Qvec);
	void continue_calib();

public slots:
	void recieveLeftImage(void * img_ptr);
	void recieveRightImage(void * img_ptr);
};

#endif // IMAGEPROCESSCONTROLER_H
