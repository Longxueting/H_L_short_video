#ifndef JSONURL_H
#define JSONURL_H

#include <QObject>

class JsonUrl:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QJsonArray jsonDataLike READ getJsonData WRITE setJsonData NOTIFY dataChanged)

public:
    JsonUrl();
};

#endif // JSONURL_H
