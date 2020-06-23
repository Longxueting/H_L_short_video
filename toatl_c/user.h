#ifndef USER_H
#define USER_H

#include <string>
#include <QObject>


class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)

public:
    User();
    User(QString user, QString pwd);
    ~User();

    QString getUsername();
    QString getPassword();

    void setUsername(QString u);
    void setPassword(QString p);

//    int sendU(QString qusername, QString qpassword);


signals:
    void usernameChanged();
    void passwordChanged();

private:
    QString m_username;
    QString m_password;
    int m_id;
};

#endif // USER_H
