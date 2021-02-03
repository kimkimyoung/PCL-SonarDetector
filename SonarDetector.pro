#-------------------------------------------------
#
# Project created by QtCreator 2021-01-19T09:20:14
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SonarDetector
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        XTFReader/frame.cpp \
        XTFReader/simulator.cpp \
        XTFReader/logger.cpp \
        XTFReader/get_value.c \
        eventlabel.cpp \
    imagesolve.cpp \
    u900DataProcess/u900DataReceive.cpp \
    u900DataProcess/u900PingTrans.cpp \
    jscontext.cpp \
    dialog.cpp \
    GeoEncoder/geoencoder.cpp

HEADERS += \
        mainwindow.h \
        XTFReader/xtf.h \
        XTFReader/status.h \
        XTFReader/simulator.h \
        XTFReader/frame.h \
        XTFReader/logger.h \
        XTFReader/get_value.h \
        XTFReader/config.h \
        eventlabel.h \
        mainwindow.h \
    imagesolve.h \
    u900DataProcess/u900DataReceive.h \
    u900DataProcess/u900PingTrans.h \
    jscontext.h \
    dialog.h \
    GeoEncoder/geoencoder.h



FORMS += \
        mainwindow.ui \
    dialog.ui

INCLUDEPATH +=  /usr/include/opencv2
                /usr/include/opencv
                /usr/include/eigen3

LIBS += /usr/lib/x86_64-linux-gnu/libopencv_highgui.so \
        /usr/lib/x86_64-linux-gnu/libopencv_core.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so \
        /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so \
        /usr/lib/x86_64-linux-gnu/libproj.so \
        /usr/lib/x86_64-linux-gnu/libopencv_photo.so \
        /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so \
        /home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/libdarknet.so \

RESOURCES += \
    qss.qrc

DISTFILES += \
    js/msgutils.js \
    js/qwebchannel.js




