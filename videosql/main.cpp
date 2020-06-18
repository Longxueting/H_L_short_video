#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "database.h"
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    Database database;

    if(database.createConection("VideoTable") && database.createConection("UserTable"))
        cout<<"创建成功"<<endl;
    if(database.userUpdate("奈奈生","u_password","159800"))
        cout<<"更新成功"<<endl;
    User user;
    user=database.UserSearch("奈奈生");
    qDebug()<<user.id<<user.age<<user.username;
//    Video video;
//    video=database.videoSearch(11);
//    qDebug()<<video.author<<video.url<<video.v_id;

//    if(database.videoInsert(11,"http://","视频描述","奈奈生","image","时间"))
//        cout<<"视频添加"<<endl;
//    if(database.userInsert(123,"奈奈生","123456"))
//        cout<<"用户添加"<<endl;
    //    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //    QGuiApplication app(argc, argv);

    //    QQmlApplicationEngine engine;
    //    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //    if (engine.rootObjects().isEmpty())
    //        return -1;

    //    return app.exec();
}
