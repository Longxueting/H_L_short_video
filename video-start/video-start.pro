QT += quick

CONFIG += console c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Load_video.cpp \
        main.cpp \
        readAllJson.cpp \
        reciver.cpp \
        videoPlay.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L /usr/localb/ -lavcodec -lavformat -lavutil -lswscale -lpthread -lm -lswresample -lx264

HEADERS += \
    Load_video.h \
    readAllJson.h \
    reciver.h \
    videoPlay.h

DISTFILES += \
    Image/heart.png \
    Image/icon_home_like_before.png \
    Image/pinglun (3).png \
    Image/redheart.png \
    Image/redheart1.png \
    Image/redheart2.png \
    Image/redheart3.png \
    Image/redheart4.png \
    Image/redheart5.png \
    Image/redheart6.png \
    Image/stop2.png \
    Image/user1.png \
    Image/video.png \
    Image/zan.png \
    Image/zan1.png \
    Image/zhuanfa.png
