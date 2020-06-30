#include "client.h"
#include <iostream>
#include "conecting_s.h"
#include <QDebug>
#include <string>

Client::Client()
{

}

int Client::sendU(QString qusername, QString qpassword, int flag)
{
    //把QString转为char *
    QByteArray sr_u = qusername.toLocal8Bit();
    int re=0;
    int len_u = sr_u.length();
    char *c_username = new char[len_u+2];
    c_username[len_u] = c_username[len_u+1]=0;
    strcpy(c_username, sr_u.data());

    std::cout<<"c_nername is: "<<c_username<<std::endl;

    QByteArray sr_p = qpassword.toLocal8Bit();
    int len_p = sr_p.length();
    char *c_password = new char[len_p+2];
    c_password[len_p] = c_password[len_p+1]=0;
    strcpy(c_password, sr_p.data());

    std::cout<<"c_password is: "<<c_password<<std::endl;

    _connecting = new Conecting_S();
    _user = _connecting->connecting(c_username, c_password, re, flag);

//    qDebug()<<"_user->getUsername() is : "<<_user->getUsername();
    m_login_re = re;
//    delete connecting;
    return re;
}

int Client::login_re() const
{
    return m_login_re;
}

void Client::setLogin_re(int login_re)
{
    m_login_re = login_re;
}

User *Client::user() const
{
    return _user;
}

void Client::setUser(User *user)
{
    _user = user;
}

void Client::needUserImag(int i)
{
    if(i==1)
        _connecting->sendID(_user->getId());
    else
        return;
}

void Client::changeIntroduce(QString introduce)
{
    _user->setIntroduce(introduce);
    QByteArray sr_introduce = introduce.toLocal8Bit();
    int len_in = sr_introduce.length();
    char *c_introduce = new char[len_in+2];
    memset(c_introduce, 0, len_in+2);
    strcpy(c_introduce, sr_introduce.data());
    std::cout<<"introduce is :"<<c_introduce<<std::endl;


    _connecting->sendIntroduce(_user->getId(), c_introduce);
}

void Client::changeSex(int sex)
{
    _connecting->sendSex(_user->getId(), sex);
}
