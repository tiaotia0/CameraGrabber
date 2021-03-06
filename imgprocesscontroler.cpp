#include "imgprocesscontroler.h"

QVector<QRgb> Gray8bitQImageCorlorTable::vcolorTable;
bool Gray8bitQImageCorlorTable::IsConstructed(false);

const QVector<QRgb>& Gray8bitQImageCorlorTable::GetGray8bitQImageCorlorTable()
{
	if (!Gray8bitQImageCorlorTable::IsConstructed)
	{
		for (int i = 0; i < 256; i++)
		{
			vcolorTable.append(qRgb(i, i, i));
		}
		IsConstructed = true;
	}
	return vcolorTable;
}

void ImageDisplayControler::HowToProcessImages(void *img_ptr, size_t img_len)
{
	BYTE* img_byte = (BYTE*)img_ptr;
	int actual_img_width = std::atoi(m_CameraParameters.m_ImageWidth.c_str());
	int actual_img_heigh = std::atoi(m_CameraParameters.m_ImageHeight.c_str());
	//QImage()constuctor: img_byte必须在构造的QImage图像生存周期内valid，为解除该特性，显式调复制构造=

	QImage qImg = QImage(img_byte, actual_img_width, actual_img_heigh, actual_img_width, QImage::Format_Indexed8);
	Gray8bitQImageCorlorTable cvt;
	qImg.setColorTable(cvt.GetGray8bitQImageCorlorTable());

	if (is_playing)
	{
		emit sendDisplayImage(qImg);
		if (is_recording)
		{
			std::string str_tmp = m_FilePathToSave + "\\" + std::to_string(picNr_toSave++) + ".TIFF";
			qImg.save(str_tmp.c_str());
		}
	}
	if (is_calibrating)
	{
		emit sendCalibImage(img_ptr);
	}
}

void CameraCalibrateControler::recieveLeftImage(void * img_ptr)
{
	left_img_ptr = img_ptr;
	while(!calib_mtx.tryLock());
	collect_img_count++;
	if (collect_img_count == camera_amount)
		emit SignalCalibrate();
	calib_mtx.unlock();
}

void CameraCalibrateControler::recieveRightImage(void * img_ptr)
{
	right_img_ptr = img_ptr;
	while (!calib_mtx.tryLock());
	collect_img_count++;
	if (collect_img_count == camera_amount)
		emit SignalCalibrate();
	calib_mtx.unlock();
}