#include "login.h"


Login::Login()
{
}

Login::Login(std::string username, std::string password)
    :m_username{username},m_password{password}
{

}

void Login::setusername(std::string username)
{
    this->m_username = username;
}
void Login::setpassword(std::string password)
{
    this->m_password = password;
}
std::string Login::getusername()
{
    return this->m_username;
}
std::string Login::getpassword()
{
    return this->m_password;
}

int Login::compared(const std::string username, const std::string password)
{
    if(username==this->m_username&&password==this->m_password)
        return 1;
    return 0;
}
Login::~Login()
{

}
