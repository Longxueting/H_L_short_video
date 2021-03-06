QT += quick
QT += sql

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
        client.cpp \
        conecting_s.cpp \
        firstimage.cpp \
        hand_data.cpp \
        loadvideo.cpp \
        main.cpp \
        readjson.cpp \
        reciver.cpp \
        uandp.cpp \
        user.cpp \
        video.cpp \
        videomodel.cpp \
        videoplay.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /usr/local/include/
LIBS += -L /usr/localb/ -lavcodec -lavformat -lavutil -lswscale -lpthread -lm -lswresample -lx264

HEADERS += \
    client.h \
    conecting_s.h \
    firstimage.h \
    hand_data.h \
    loadvideo.h \
    readjson.h \
    reciver.h \
    uandp.h \
    user.h \
    video.h \
    videomodel.h \
    videoplay.h
