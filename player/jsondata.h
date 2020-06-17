#ifndef JSONDATA_H
#define JSONDATA_H

#include <QString>
#include <QObject>
#include <QJsonArray>

//struct Video{
//    int m_index;
//    int m_herat_num;
//    bool m_isLike;
//    QString m_video_source;
//    QString m_image;
//};

class JsonData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QJsonArray jsonData READ read /*WRITE write NOTIFY jsonDataChanged*/)


public:
    JsonData(QObject *parent = nullptr);

    QJsonArray read();
    void write();

signals:
    void dataChanged();

private:
    QJsonArray jsonData;

};

#endif // JSONDATA_H
