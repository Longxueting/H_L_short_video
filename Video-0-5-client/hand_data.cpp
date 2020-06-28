#include "hand_data.h"
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <QString>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#define BUF_SIZE 1024
using namespace std;
Hand_Data::Hand_Data()
{

}

User* Hand_Data::handUser(int sock, int &re)
{
    char receive[BUF_SIZE];
    read(sock, receive, BUF_SIZE);//第一次读取服务器数据,返回是否成功登录
    re = stoi(receive);//转为int类型

    User *user = new User();
    if(re==0){
        read(sock, receive, BUF_SIZE);//第二次读取用户的信息
        ofstream userOs;
        string tableUserName = "/root/UserTable.json";
        userOs.open( tableUserName.c_str() );
        userOs << receive;//写入文件

        QString qstring = QString(QString::fromLocal8Bit(receive));//转为QString
        qDebug()<<"qstring is: "<<qstring;
        QJsonDocument doc1 = QJsonDocument::fromJson(qstring.toUtf8());
        QJsonArray array = doc1.array();//转为QJ是哦你Array
//        QJsonObject object = doc1.object();
        qDebug()<<"array is: "<<array;

        qDebug()<<"u_age is :"<<array.at(0).toObject()["u_age"].toInt();
        qDebug()<<"u_id is :"<<array.at(0).toObject()["u_id"].toInt();
        qDebug()<<"u_img is :"<<array.at(0).toObject()["u_img"].toString();
        qDebug()<<"u_introduce is :"<<array.at(0).toObject()["u_introduce"].toString();
        qDebug()<<"u_local is :"<<array.at(0).toObject()["u_local"].toString();
        qDebug()<<"u_password is :"<<array.at(0).toObject()["u_password"].toString();
        qDebug()<<"u_sex is :"<<array.at(0).toObject()["u_sex"].toInt();
        qDebug()<<"u_username is :"<<array.at(0).toObject()["u_username"].toString();



        user->setId(array.at(0).toObject()["u_id"].toInt());
        std::cout<<"GT"<<std::endl;
        user->setAge(array.at(0).toObject()["u_age"].toInt());
        user->setImg(array.at(0).toObject()["u_img"].toString());
        user->setSex(array.at(0).toObject()["u_sex"].toInt());
        user->setPassword(array.at(0).toObject()["u_password"].toString());
        user->setUsername(array.at(0).toObject()["u_username"].toString());
        user->setIntroduce(array.at(0).toObject()["u_introduce"].toString());
        userOs.close();
    }

    return user;
}
void Hand_Data::handVideo(int sock)
{
    ofstream videoOs;
    string tableVideoName = "/root/VideoTable.json";
    videoOs.open( tableVideoName.c_str() );


    char receive[BUF_SIZE];
    int readlen=0;
    sleep(1);
    while (readlen=read(sock,receive,BUF_SIZE)) {
        string content(receive,readlen);
        videoOs<<content;
//        cout << content << endl;
        if(readlen<BUF_SIZE)
        {
            cout<<"我要退出"<<endl;
            break;
        }
    }
    cout<<"退出"<<endl;
    videoOs.close();
}
