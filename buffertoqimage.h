#ifndef BUFFERTOQIMAGE_H
#define BUFFERTOQIMAGE_H

#include <QImage>
#include <Windows.h>
#include <assert.h>
#include <QVector>
#include <memory>

class BufferToQImage {
public:
  BufferToQImage();
  ~BufferToQImage();
  QImage Pk8bitGrayToQIm(const BYTE *pBuffer, const int &bufWidth, const int &bufHight);

private:
  QVector<QRgb> vcolorTable;

};

#endif
