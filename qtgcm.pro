TEMPLATE = app

QT = core network qml quick gui androidextras

SOURCES += main.cpp \
    notificationreceiver.cpp \
    androidnotificationreceiver.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/libs/*.jar \
    android/AndroidManifest.xml \
    android/src/com/cutehacks/examples/qtgcm/*.java \
    android/res/values/*.xml

HEADERS += \
    notificationreceiver.h \
    androidnotificationreceiver.h
