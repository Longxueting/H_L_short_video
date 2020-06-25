#ifndef READALLJSON_H
#define READALLJSON_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

class ReadJson
{
public:
    ReadJson();

    void readJsonFile(const QJsonArray &json);
    void writeJsonFile(QJsonArray &json)const;

    QJsonObject getOneData(int i);
    QJsonArray getFiveData();

    bool loadJson();
    bool saveJson();


private:

    QJsonArray m_allJsonData;
};

#endif // READALLJSON_H
