#ifndef IMAGECONTROLER_H
#define IMAGECONTROLER_H

#include "siliconboard.h"
#include <QImage>
#include <Windows.h>
#include <assert.h>
#include <QVector>
#include <memory>

class BufferToQImage {
public:
	BufferToQImage();
	~BufferToQImage();
	QImage Pk8bitGrayToQIm(const BYTE *pBuffer, const int bufWidth, const int bufHight);

private:
	static QVector<QRgb> vcolorTable;
	static bool is_vcolorTable_constructed;

};

class ImageDisplayControler : public QObject, public Base_ImageContrler
{
    Q_OBJECT

public:
    ImageDisplayControler(ImageCaptureBoard & img_cap_board, size_t port_index) :Base_ImageContrler(img_cap_board, port_index) {}
    void HowToProcessImages(void *img_prt, size_t img_len) override;
signals:
    void sendImage(QImage qImg);
};

#endif // IMAGECONTROLER_H
