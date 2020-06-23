#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QObject>

class Client : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged)
//    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)
public:
    Client();
    Q_INVOKABLE int sendU(QString qusername, QString qpassword);
};

#endif // CLIENT_H
