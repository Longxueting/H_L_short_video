#ifndef UANDP_H
#define UANDP_H

#include <QObject>
//#include <string>

#include "user.h"

class UAndP : public QObject
{
    Q_OBJECT
    Q_ENUMS(Status)
    Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(User* user READ user WRITE setUser NOTIFY statusChanged)

public:

    enum Status{
        Changed,
        Checking,
        Logined,
        Register,
        PasswordError,
        NotUser
    };

    UAndP();
    virtual ~UAndP();

    User *user();
    void setUser(User* u);

    Status status() const;

    void setStatus(const Status &status);

signals:
    void statusChanged();
    void userChanged();
//    void msgChanged();

public slots:

private:

    User *_user;
    Status m_status;

};

#endif // UANDP_H
