#include <QGuiApplication>
#include "User.h"
#include "UAndP.h"

#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<User>("user",1,0,"User");
    qmlRegisterType<UAndP>("user",1,0,"UserAndPassowrd");

//    QObject *object = new QQmlComponent(engine.rootObjects());
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
//    qDebug() << "username is " << QQmlProperty::read(object, "username").toString();
//    qDebug() << "password is " << QQmlProperty::read(object, "password").toString();
    engine.load(url);



    return app.exec();
}
