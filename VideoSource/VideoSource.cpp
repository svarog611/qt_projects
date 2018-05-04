#include "VideoSource.h"
#include "MemoryVideoBuffer.h"

#include <QAbstractVideoSurface>

VideoSource::VideoSource(QObject* parent)
    : QObject(parent)
    , m_surface(nullptr)
    , m_buffer(new MemoryVideoBuffer)
{}

VideoSource::~VideoSource()
{
    closeSurface();
    delete m_buffer;
}

QAbstractVideoSurface* VideoSource::videoSurface() const
{
    return m_surface;
}

QString VideoSource::accessKey() const
{
    return m_accessKey;
}

void VideoSource::setVideoSurface(QAbstractVideoSurface* surface)
{
    closeSurface();
    m_surface = surface;

    if (m_format.isValid())
        m_surface->start(m_format);
}

void VideoSource::setImage(const uchar* data, int byteCount, int bytesPerLine)
{
    if (m_surface)
    {
        m_buffer->setData(data, byteCount, bytesPerLine);
        m_surface->present(m_frame);
    }
}

void VideoSource::setAccessKey(const QString& key)
{
    if (m_accessKey != key)
    {
        m_accessKey = key;
        emit accessKeyChanged(m_accessKey);
    }
}

void VideoSource::setVideoFormat(int width, int height, QImage::Format pixelFormat)
{
    QVideoSurfaceFormat format(QSize(width, height), QVideoFrame::pixelFormatFromImageFormat(pixelFormat));

    if (m_format != format)
    {
        m_format = format;
        m_frame = QVideoFrame(m_buffer, format.frameSize(), format.pixelFormat());

        m_surface->stop();
        m_surface->start(m_format);
    }
}

void VideoSource::closeSurface()
{
    if (m_surface && m_surface->isActive())
        m_surface->stop();
}
