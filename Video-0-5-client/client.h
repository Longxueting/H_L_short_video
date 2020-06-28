#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QObject>
#include "user.h"


class Client : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged)
//    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)
public:
    Client();
    Q_INVOKABLE int sendU(QString qusername, QString qpassword);

    Q_INVOKABLE int login_re() const;
    void setLogin_re(int login_re);

    Q_INVOKABLE User *user() const;
    void setUser(User *user);

private:
    int m_login_re;
    User *_user;

};

#endif // CLIENT_H
