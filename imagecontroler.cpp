#include "imagecontroler.h"

BufferToQImage::BufferToQImage() {
	if (!is_vcolorTable_constructed)
	{
		for (int i = 0; i < 256; i++)
		{
			vcolorTable.append(qRgb(i, i, i));
		}
		is_vcolorTable_constructed = true;
	}
}

QVector<QRgb> BufferToQImage::vcolorTable;
bool BufferToQImage::is_vcolorTable_constructed = false;

BufferToQImage::~BufferToQImage() {}

QImage BufferToQImage::Pk8bitGrayToQIm(const BYTE *pBuffer, const int bufWidth, const int bufHight)
{
	assert((pBuffer != NULL) && (bufWidth > 0) && (bufHight > 0));
	int biBitCount = 8;
	int lineByte = (bufWidth * biBitCount / 8 + 3) / 4 * 4;

	if (bufWidth == lineByte)
	{
		QImage qIm = QImage(pBuffer, bufWidth, bufHight, QImage::Format_Indexed8);
		qIm.setColorTable(vcolorTable);
		return qIm;
	}
	else
	{
		BYTE *qImageBuffer = new BYTE[lineByte * bufHight];
		uchar *QImagePtr = qImageBuffer;

		for (int i = 0; i < bufHight; i++)
		{
			memcpy(QImagePtr, pBuffer, bufWidth);
			QImagePtr += lineByte;
			pBuffer += bufWidth;
		}
		QImage qImage = QImage(qImageBuffer, bufWidth, bufHight, QImage::Format_Indexed8);
		delete qImageBuffer;
		qImage.setColorTable(vcolorTable);
		delete[]qImageBuffer; 
		return qImage;
	}
}

void ImageDisplayControler::HowToProcessImages(void *img_prt, size_t img_len)
{
    BYTE* img_byte = (BYTE*) img_prt;
	size_t actual_img_heigh = std::atoi(m_CameraParameters.m_ImageHeight.c_str());
	size_t actual_img_width = std::atoi(m_CameraParameters.m_ImageWidth.c_str());
	actual_img_width = actual_img_width > 1024 ? 1024 : actual_img_width;
	if (is_recording)
	{
		picNr_toSave++;
	}
    BufferToQImage cvt;
	QImage qImg = cvt.Pk8bitGrayToQIm(img_byte, actual_img_heigh, actual_img_width);
	emit sendImage(qImg);
}
