#ifndef USER_H
#define USER_H

#include <string>
#include <QObject>
#include <vector>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)

public:
    User();
    User(QString user, QString pwd);
    ~User();

    Q_INVOKABLE QString getUsername();
    QString getPassword();

    void setUsername(QString u);
    void setPassword(QString p);

//    int sendU(QString qusername, QString qpassword);


    int getAge() const;
    void setAge(int age);

    Q_INVOKABLE int getId() const;
    void setId(int id);

    QString getImg() const;
    void setImg(const QString &img);

    Q_INVOKABLE QString getIntroduce() const;
    void setIntroduce(const QString &introduce);

    int getSex() const;
    void setSex(int sex);

    QString getTags() const;
    void setTags(const QString &tags);

    Q_INVOKABLE std::vector<QString> get_tags();

signals:
    void usernameChanged();
    void passwordChanged();

private:
    int m_age;
    int m_id;
    QString m_img;
    QString m_introduce;
    QString m_username;
    int m_sex;
    QString m_password;
    QString m_tags;
};

#endif // USER_H
