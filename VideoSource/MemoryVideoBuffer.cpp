#include "MemoryVideoBuffer.h"

MemoryVideoBuffer::MemoryVideoBuffer()
    : QAbstractVideoBuffer(QAbstractVideoBuffer::NoHandle)
    , m_data(nullptr)
    , m_byteCount(-1)
    , m_bytesPerLine(-1)
    , m_mapMode(NotMapped)
{}

MemoryVideoBuffer::~MemoryVideoBuffer()
{}

QAbstractVideoBuffer::MapMode MemoryVideoBuffer::mapMode() const
{
    return m_mapMode;
}

uchar* MemoryVideoBuffer::map(MapMode mode, int* numBytes, int* bytesPerLine)
{
    const uchar* result = nullptr;

    if (m_data && m_mapMode == NotMapped && mode != NotMapped)
    {
        m_mapMode = mode;

        *numBytes = m_byteCount;
        *bytesPerLine = m_bytesPerLine;

        result = m_data;
    }

    return const_cast<uchar*>(result);
}

void MemoryVideoBuffer::unmap()
{
    m_mapMode = NotMapped;
}

void MemoryVideoBuffer::setData(const uchar* data, int byteCount, int bytesPerLine)
{
    m_data = data;
    m_byteCount = byteCount;
    m_bytesPerLine = bytesPerLine;
}
