#include "imagedisplaycontroler.h"


void ImageDisplayControler::HowToProcessImages(void *img_prt, size_t picNr, size_t img_len)
{
    BYTE* img_byte = (BYTE*) img_prt;
    BufferToQImage cvt;
    QImage qImg = cvt.Pk8bitGrayToQIm(img_byte, m_ImageWidth, m_ImageHeight);

    emit sendImage(qImg);
}
