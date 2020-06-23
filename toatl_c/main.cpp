#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "uandp.h"
#include "user.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<User>("user",1,0,"User");
    qmlRegisterType<UAndP>("user",1,0,"UserAndPassowrd");

    QScopedPointer<Client> client(new Client);
    engine.rootContext()->setContextProperty("client", client.data());

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
