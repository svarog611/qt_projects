#include "VideoSource_plugin.h"
#include "VideoSource.h"

#include <qqml.h>

void VideoSourcePlugin::registerTypes(const char* uri)
{
    qmlRegisterType<VideoSource>(uri, 1, 0, "VideoSource");
}


