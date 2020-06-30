#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QObject>
#include "user.h"
#include "conecting_s.h"


class Client : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged)
//    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)
public:
    Client();
    Q_INVOKABLE int sendU(QString qusername, QString qpassword, int flag);

    Q_INVOKABLE int login_re() const;
    void setLogin_re(int login_re);

    Q_INVOKABLE User *user() const;
    void setUser(User *user);

    Q_INVOKABLE void needUserImag(int i);

    Q_INVOKABLE void changeIntroduce(QString introduce);
    Q_INVOKABLE void changeSex(int sex);


private:
    int m_login_re;
    User *_user;
    Conecting_S *_connecting;

};

#endif // CLIENT_H
