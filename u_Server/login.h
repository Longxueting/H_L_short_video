#ifndef LOGIN_H
#define LOGIN_H

#include <string>

class Login
{
public:
    Login();
    Login(std::string username, std::string password);
    ~Login();
    void setusername(std::string username);
    void setpassword(std::string password);
    std::string getusername();
    std::string getpassword();
    int compared(const std::string username,const std::string password);
private:
    std::string m_username;
    std::string m_password;
};

#endif // LOGIN_H
