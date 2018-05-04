#pragma once

#include <QImage>

class AbstractVideoSource
{
public:
    virtual ~AbstractVideoSource(){}

    void setImage(const QImage& image) { setImage(image.constBits(), image.byteCount(), image.bytesPerLine()); }
    virtual void setImage(const uchar* data, int byteCount, int bytesPerLine) = 0;

    virtual void setVideoFormat(int width, int height, QImage::Format imageFormat) = 0;
};
