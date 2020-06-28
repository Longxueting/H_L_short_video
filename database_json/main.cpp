#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <string>
#include <vector>
#include "json/json.h"
#include <fstream>
#include <cstdlib>
#include <mysql/mysql.h>
#include "getjson.h"
using namespace std;
int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    return app.exec();
    GetJson json;
    //json.GetTableJson("UserTable");
    //json.GetOriginalVideo("gt");
//    string tags="abcd";
//    char tag[]={0};
//    strncpy(tag,tags.c_str(),tags.length()+1);
//    for(int i=0;i<tags.length();i++){
//        cout<<"tag["<<i<<"] :"<<tag[i]<<endl;
//    }
    json.getTagJson("a");
}
