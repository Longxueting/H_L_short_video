#include "Load_video.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <QQmlContext>
#include "readAllJson.h"
#include "videoPlay.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    LoadVideo a;
//    a.loadOneVideo("rtmp://127.0.0.1/vod/04.mp4",4);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QScopedPointer<VideoPlay> videoPlay(new VideoPlay);
    engine.rootContext()->setContextProperty("videoplay", videoPlay.data());

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();

//    LoadVideo load;
//    load.loadOneVideo("rtmp://127.0.0.1/vod/04.mp4",4);
//    VideoPlay videoplay;
//    ReadJson videojson;
//    LoadVideo loadVideo;
//    videoplay.down_slide(2,4);
//    QJsonObject video=videojson.getOneData(5);
//    loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),4);
//    cout<<video["v_url"].toString().toStdString()<<endl;

}
