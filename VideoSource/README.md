This is Qt plugin, specially written for rapid image transfer from C++ to QML scene.

Compilation:
- requires Qt >= 5.5

Installation:
- copy directory VideoSource to %QT_PATH%\\%QT_VERSION%\\%COMPILER%\\qml

Usage:
c++ side:
```c++
#include "AbstractVideoSource.h"
...
QTimer timer;
QImage i; // your image here

QObject::connect(&timer, &QTimer::timeout, [&i]
{
    AbstractVideoSource* videoSourceItem; // search for your item with QQuickItem::findChildren or any other way
    videoSourceItem->setImage(i);
});

timer.setInterval(20);
timer.start();
```

QML side:
```
import VideoSource 1.0

VideoSource {
    id: videoSource
}

VideoOutput {
    source: videoSource
}
```
