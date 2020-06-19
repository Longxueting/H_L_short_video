#include "UAndP.h"

UAndP::UAndP(){
    _user = new User("username", "password");
}

UAndP::~UAndP(){
    delete _user;
}

User *UAndP::user()
{
    return _user;
}

void UAndP::setUser(User *u)
{
    _user->setUsername(u->username());
    _user->setPassword(u->password());
    m_status = Status::Becoming;
    emit statusChanged();
}


UAndP::Status UAndP::status() const
{
    return m_status;
}


