#ifndef IMAGECONTROLER_H
#define IMAGECONTROLER_H

#include "siliconboard.h"
#include <QImage>
#include <Windows.h>
#include <assert.h>
#include <QVector>
#include <memory>

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
    ImageDisplayControler(ImageCaptureBoard & img_cap_board, size_t port_index) :Base_ImageContrler(img_cap_board, port_index) {}
    void HowToProcessImages(void *img_prt, size_t img_len) override;
signals:
    void sendImage(QImage qImg);
};

#endif // IMAGECONTROLER_H
