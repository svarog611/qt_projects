TARGET = VideoSource
TEMPLATE = lib

QT += qml quick multimedia
CONFIG += qt plugin

DESTDIR = $$PWD/../build/$$TARGET

win32 {
    system(mkdir ..\build\\$$TARGET)
    system(xcopy $$TARGET\\qmldir Sukhoi\\$$TARGET /Y)
}

TARGET = $$qtLibraryTarget($$TARGET)

DEPENDPATH += \
    $$INCLUDEPATH

SOURCES += \
    VideoSource.cpp \
    VideoSource_plugin.cpp \
    MemoryVideoBuffer.cpp

HEADERS += \
    VideoSource.h \
    VideoSource_plugin.h \
    MemoryVideoBuffer.h \
    AbstractVideoSource.h

DISTFILES = qmldir
