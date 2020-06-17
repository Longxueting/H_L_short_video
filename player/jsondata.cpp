#include "jsondata.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <string>
#include <iostream>
#include <QString>
#include <vector>

JsonData::JsonData(QObject *parent) : QObject (parent)
{
//    jsonData = read();
}
QJsonArray JsonData::read()
{
    int i;
    QJsonArray subArray;
    QJsonObject subObj;
    QFile loadFile("/run/media/root/study/H&L/json/02.json");
    if(!loadFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "could't open projects json";
//        return 0;
    }
    QByteArray allData = loadFile.readAll();
    loadFile.close();

    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));
    if(json_error.error != QJsonParseError::NoError)

    {
        qDebug() << "json error!";
//        return 0;
    }

    QJsonObject rootObj = jsonDoc.object();

    QStringList keys = rootObj.keys();
    for(i = 0; i < keys.size(); i++)
    {
        qDebug() << "key" << i << " is:" << keys.at(i);
    }

    if(rootObj.contains("video"))
    {
       jsonData = rootObj.value("video").toArray();

       for(i = 0; i< subArray.size(); i++){
          subObj = subArray.at(i).toObject();
          jsonData.append(subObj);
          qDebug()<<"id is:" << subObj["id"].toInt();
          qDebug()<<"heart_num is:" << subObj["heart_num"].toInt();
          qDebug()<<"isLike is:" << subObj["isLike"].toBool();
          qDebug()<<"video_source is:" << subObj["video_source"].toString();
       }
    }
    return jsonData;
}

void JsonData::write()
{
}
