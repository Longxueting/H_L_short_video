#include "user.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include "conecting_s.h"

#define BUF_SIZE 1026

User::User(){}

User::User(QString user, QString pwd)
{
    m_username = user;
    m_password = pwd;
}

User::~User(){}

QString User::getUsername()
{
    return m_username;
}

QString User::getPassword()
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

int User::getAge() const
{
    return m_age;
}

void User::setAge(int age)
{
    m_age = age;
}

int User::getId() const
{
    return m_id;
}

void User::setId(int id)
{
    m_id = id;
}

QString User::getImg() const
{
    return m_img;
}

void User::setImg(const QString &img)
{
    m_img = img;
}

QString User::getIntroduce() const
{
    return m_introduce;
}

void User::setIntroduce(const QString &introduce)
{
    m_introduce = introduce;
}

int User::getSex() const
{
    return m_sex;
}

void User::setSex(int sex)
{
    m_sex = sex;
}

QString User::getTags() const
{
    return m_tags;
}

void User::setTags(const QString &tags)
{
    m_tags = tags;
}

std::vector<QString> User::get_tags()
{
    std::vector<QString> tags;
    QString tag;
    for(int i=0; i<3; i++){
        if(m_tags[i]=='a'){
            tag = "音乐";
            tags.push_back(tag);
        }
        if(m_tags[i]=='b'){
            tag = "运动";
            tags.push_back(tag);
        }
        if(m_tags[i]=='c'){
            tag = "萌宠";
            tags.push_back(tag);
        }
    }
    return tags;
}
//int User::sendU(QString qusername, QString qpassword)
//{
//    //把QString转为char *
//    QByteArray sr_u = qusername.toLocal8Bit();
//    int len_u = sr_u.length();
//    char *c_username = new char[len_u+2];
//    c_username[len_u] = c_username[len_u+1]=0;
//    strcpy(c_username, sr_u.data());

//    std::cout<<"c_nername is: "<<c_username<<std::endl;

//    QByteArray sr_p = qpassword.toLocal8Bit();
//    int len_p = sr_p.length();
//    char *c_password = new char[len_p+2];
//    c_password[len_p] = c_password[len_p+1]=0;
//    strcpy(c_password, sr_p.data());

//    std::cout<<"c_password is: "<<c_password<<std::endl;

//    ClientT *clientt = new ClientT();
//    clientt->sendT(c_username, c_password);

//    delete clientt;
//    return 0;
//}
