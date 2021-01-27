QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qtcvwindow.cpp

HEADERS += \
    qtcvwindow.h

FORMS += \
    qtcvwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32 {
    win32:CONFIG(release, debug|release): LIBS += -LC:/opencv/opencv451x/opencv-4.5.1/build/install/x64/vc16/lib/ -lopencv_world451
    else:win32:CONFIG(debug, debug|release): LIBS += -LC:/opencv/opencv451x/opencv-4.5.1/build/install/x64/vc16/lib/ -lopencv_world451d
    INCLUDEPATH += C:/opencv/opencv451x/opencv-4.5.1/build/install/include
    DEPENDPATH += C:/opencv/opencv451x/opencv-4.5.1/build/install/include
}

macx {
    macx: LIBS += -L /usr/local/Cellar/opencv/4.5.0_5/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
    INCLUDEPATH += /usr/local/Cellar/opencv/4.5.0_5/include/opencv4
    DEPENDPATH += /usr/local/Cellar/opencv/4.5.0_5/include/opencv4v
}


