#include "BufferToQImage.h"

BufferToQImage::BufferToQImage() {
    for (int i = 0; i < 256; i++)
    {
        vcolorTable.append(qRgb(i, i, i));
    }
}

BufferToQImage::~BufferToQImage() {}

QImage BufferToQImage::Pk8bitGrayToQIm(const BYTE *pBuffer, const int &bufWidth, const int &bufHight)
{
    assert((pBuffer != NULL) && (bufWidth>0) && (bufHight>0));

    int biBitCount = 8;
    int lineByte = (bufWidth * biBitCount/8 + 3) / 4 * 4;

    if (bufWidth == lineByte)
    {
        QImage qIm = QImage(pBuffer, bufWidth, bufHight, QImage::Format_Indexed8);
        qIm.setColorTable(vcolorTable);

        return qIm;
    }
    else
    {
		//std::shared_ptr<BYTE*> qImageBuffer = std::make_shared<BYTE*>(lineByte * bufHight);
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

        return qImage;
    }
}
