#include "readjson.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <QJsonArray>

using namespace std;

ReadJson::ReadJson(){
    loadJson();
}

void ReadJson::readJsonFile(const QJsonArray &json)
{
    for (int index = 0; index < json.size(); index++) {
        QJsonObject onevideo;
        onevideo = json[index].toObject();
        onevideo.insert("isLike", false);
        m_allJsonData.append(onevideo);
    }
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
    //loadJson();
    return m_allJsonData[i].toObject();
}

QJsonArray ReadJson::getFiveData()
{
    if(m_allJsonData.count() != 0){
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
    QFile loadFile(QStringLiteral("/run/media/root/study/H&L/VideoTable.json"));

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

void ReadJson::changeLikeNum(int videoIndex, int likeNum,bool isLike)
{
    QJsonObject onevideo;
    onevideo=m_allJsonData[videoIndex].toObject();
    onevideo.insert("v_like_num", likeNum);
    onevideo.insert("isLike", isLike);
    m_allJsonData[videoIndex] = onevideo;
}
