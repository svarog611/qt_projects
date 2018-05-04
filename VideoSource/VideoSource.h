#pragma once

#include <QObject>
#include <QVideoSurfaceFormat>

#include "AbstractVideoSource.h"

class QAbstractVideoSurface;
class MemoryVideoBuffer;

class VideoSource : public QObject, public AbstractVideoSource
{
    Q_OBJECT

public:
    explicit VideoSource(QObject* parent = nullptr);
    ~VideoSource() override;

public: // AbstractVideoSource
    void setImage(const uchar* data, int byteCount, int bytesPerLine) override;
    void setVideoFormat(int width, int height, QImage::Format pixelFormat) override;

public:
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface)
    Q_PROPERTY(QString                accessKey    READ accessKey    WRITE setAccessKey NOTIFY accessKeyChanged)

    QAbstractVideoSurface* videoSurface() const;
    void setVideoSurface(QAbstractVideoSurface* surface);

    QString accessKey() const;
    void setAccessKey(const QString& accessKey);

signals:
    void accessKeyChanged(const QString& newKey);

private:
    void closeSurface();

private:
    QAbstractVideoSurface* m_surface;
    MemoryVideoBuffer* m_buffer;
    QVideoSurfaceFormat m_format;
    QString m_accessKey;
    QVideoFrame m_frame;
};
