#include "uandp.h"

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
    _user->setUsername(u->getUsername());
    _user->setPassword(u->getPassword());
    m_status = Status::Changed;
    emit statusChanged();
}


UAndP::Status UAndP::status() const
{
    return m_status;
}

void UAndP::setStatus(const Status &status)
{
    m_status = status;
    emit statusChanged();
}


