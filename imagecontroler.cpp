#include "imagecontroler.h"

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

void ImageDisplayControler::HowToProcessImages(void *img_prt, size_t img_len)
{
	BYTE* img_byte = (BYTE*)img_prt;
	int actual_img_width = std::atoi(m_CameraParameters.m_ImageWidth.c_str());
	int actual_img_heigh = std::atoi(m_CameraParameters.m_ImageHeight.c_str());

	QImage qImg(img_byte, actual_img_width, actual_img_heigh, actual_img_width, QImage::Format_Indexed8);
	Gray8bitQImageCorlorTable cvt;
	qImg.setColorTable(cvt.GetGray8bitQImageCorlorTable());
	emit sendImage(qImg);
	if (is_recording)
	{
		std::string str_tmp = m_FilePathToSave + "\\" + std::to_string(picNr_toSave++) + ".TIFF";
		qImg.save(str_tmp.c_str());
	}
}
