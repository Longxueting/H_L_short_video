#ifndef USER_H
#define USER_H

#include <string>
#include <QObject>


class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)

public:
    User();
    User(QString user, QString pwd);
    ~User();

    QString username();
    QString password();

    void setUsername(QString u);
    void setPassword(QString p);

signals:
    void usernameChanged();
    void passwordChanged();

private:
    QString m_username;
    QString m_password;

};

#endif // USER_H
