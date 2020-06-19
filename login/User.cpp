#include "User.h"

User::User(){}

User::User(QString user, QString pwd)
{
    m_username = user;
    m_password = pwd;
}

User::~User(){}

QString User::username()
{
    return m_username;
}

QString User::password()
{
    return m_password;
}

void User::setUsername(QString u)
{
    m_username = u;
}

void User::setPassword(QString p)
{
    m_password = p;
}


