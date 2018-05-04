#pragma once

#include <QAbstractVideoBuffer>

class MemoryVideoBuffer : public QAbstractVideoBuffer
{
public:
    MemoryVideoBuffer();
    ~MemoryVideoBuffer() override;

public:
    MapMode mapMode() const override;

    uchar* map(MapMode mode, int* numBytes = nullptr, int* bytesPerLine = nullptr) override;
    void unmap() override;

    void setData(const uchar* data, int byteCount, int bytesPerLine);

private:
    const uchar* m_data;
    int m_byteCount;
    int m_bytesPerLine;
    QAbstractVideoBuffer::MapMode m_mapMode;
};
