#include "readAllJson.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>

ReadJson::ReadJson(){}

void ReadJson::readJsonFile(const QJsonArray &json)
{
    m_allJsonData = json;
}

void ReadJson::writeJsonFile(QJsonArray &json) const
{
    QJsonArray jsonarray;
    for (int index = 0; index < m_allJsonData.size(); index++) {
        QJsonObject onevideo;
        onevideo = m_allJsonData[index].toObject();
        qDebug() << m_allJsonData[index]["isLike"];
        jsonarray.append(onevideo);
    }
    json = jsonarray;
}

QJsonObject ReadJson::getOneData(int i)
{
    loadJson();
    return m_allJsonData[i].toObject();
}

QJsonArray ReadJson::getFiveData()
{
    if(loadJson()){
        QJsonArray fiveJson;
        for(int index = 0; index < 5; index++){
            QJsonObject onevideo;
            onevideo = m_allJsonData.at(index).toObject();
            fiveJson.append(onevideo);
        }
        return fiveJson;
    }
    QTextStream(stdout) << "Here is error\n";
    QJsonArray my;
    return my;
}

bool ReadJson::loadJson()
{
    QFile loadFile(QStringLiteral("/root/videoview/jsonRead/VideoTable.json"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    readJsonFile(loadDoc.array());

    QTextStream(stdout) << "Loaded save for "
                        << loadDoc["video"][1]["heart_num"].toInt()
            << " using "
            << "JSON...\n";
    return true;
}

bool ReadJson::saveJson()
{
    QFile saveFile(QStringLiteral("dydata.json"));

    if(!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.....");
        return false;
    }

    QJsonArray testObject;
    writeJsonFile(testObject);
    QJsonDocument saveDoc(testObject);
    saveFile.write(saveDoc.toJson());

    QTextStream(stdout) << "Loaded save for "
                           //<< saveDoc["video"][0]["isLike"].toBool()
                        <<" using JSON ... END1\n";

    return true;
}


