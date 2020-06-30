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
#include <sstream>

#define BUF_SIZE 1024
#define MAXLINE 4096
using namespace std;
Hand_Data::Hand_Data()
{

}

User* Hand_Data::handUser(int& sock, int &re)
{
    char receive[BUF_SIZE];
    read(sock, receive, BUF_SIZE);//第一次读取服务器数据,返回是否成功登录
    re = stoi(receive);//转为int类型

    std::cout<<"GT re is : "<<re<<std::endl;

    User *user = new User();
    if(re==0){
        cout<<"成功"<<endl;
        read(sock, receive, BUF_SIZE);//第二次读取用户的信息
        ofstream userOs;
        string tableUserName = "/run/media/root/study/H&L/UserTable.json";
        userOs.open( tableUserName.c_str() );
        userOs << receive;//写入文件

        QString qstring = QString(QString::fromLocal8Bit(receive));//转为QString
        qDebug()<<"qstring is: "<<qstring;
        QJsonDocument doc1 = QJsonDocument::fromJson(qstring.toUtf8());
        QJsonArray array = doc1.array();//转为QJsonArray
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
        user->setAge(array.at(0).toObject()["u_age"].toInt());
        user->setImg(array.at(0).toObject()["u_img"].toString());
        user->setSex(array.at(0).toObject()["u_sex"].toInt());
        user->setPassword(array.at(0).toObject()["u_password"].toString());
        user->setUsername(array.at(0).toObject()["u_username"].toString());
        user->setIntroduce(array.at(0).toObject()["u_introduce"].toString());
        user->setTags(array.at(0).toObject()["u_tag"].toString());
        userOs.close();
    }
    if(re==-1){
        std::cout<<"密码错误"<<std::endl;
        return nullptr;
    }
    if(re==-2){
        std::cout<<"用户名不存在"<<std::endl;
        return nullptr;
    }
    if(re==-3){
        std::cout<<"该用户以存在"<<std::endl;
        return nullptr;
    }
    return user;
}
void Hand_Data::handVideo(int &sock)
{
    ofstream videoOs;
    string tableVideoName = "/run/media/root/study/H&L/VideoTable.json";
    videoOs.open( tableVideoName.c_str() );


    char receive[BUF_SIZE];
//    int times;

//    read(sock, receive, BUF_SIZE);
//    times = stoi(receive);//转为int类型

    int readlen=0;
    sleep(1);
    while (readlen=read(sock,receive,BUF_SIZE)) {
        string content(receive,readlen);
        videoOs<<content;
        if(readlen<BUF_SIZE)
        {
            cout<<"我要退出"<<endl;
            break;
        }
    }

//    int i=0;
//    while(1){
//        readlen = read(sock, receive, BUF_SIZE);
//        i=0;
//        string content(receive,readlen);
//        videoOs<<content;
//        if(readlen == 0||content[i]=='\''){
//            break;
//        }
//        i++;
//    }

//    read(sock,receive,BUF_SIZE);
//    videoOs<<receive;
    cout<<"退出"<<endl;
    videoOs.close();
}

void Hand_Data::handImg(int id, int &sock)
{
    string userIds = std::to_string(id);
    char userIdc[userIds.length()+1];
    userIdc[0] = 'a';
    strcat(userIdc, userIds.c_str());
    write(sock, userIdc, userIds.length()+1);
    char  buff[4096];
    FILE *fp;
    int  n;
//    if((fp = fopen("/run/media/root/study/H&L/new1.jpg","wb") ) == nullptr )
//    {
//        printf("File.\n");
//        close(sock);
//        exit(1);
//    }

//    stringstream ss;
    string file = "/run/media/root/study/H&L/new1.jpg";
    ofstream out(file, ios::app | ios::binary);
    while (1) {
        n = read(sock, buff, MAXLINE);
        if(n == 0){
            break;
        }
        out.write(buff, n);
    }

//    while(1){
//        n = read(sock, buff, MAXLINE);
//        if(n == 0){
////            std::cout<<"n=0"<<std::endl;
//            break;
//        }
//        fwrite(buff, 1, n, fp);
//    }
//    buff[n] = '\0';
//    fclose(fp);


//    close(sock);
}

void Hand_Data::handIntroduce(int id, int &sock, char *introduce)
{
    string userIds = std::to_string(id);
    char userIdIntroduce[BUF_SIZE];

    userIdIntroduce[0] = 'b';
    strcat(userIdIntroduce, userIds.c_str());
    strcat(userIdIntroduce, introduce);

    cout<<"发送的简介信息是:"<<userIdIntroduce<<endl;
    if(write(sock, userIdIntroduce, strlen(userIdIntroduce)) <= 0)
        std::cout<<"简介信息发送失败"<<endl;
    else
        std::cout<<"成功将修改的简介信息发送出去"<<std::endl;
}

void Hand_Data::handSex(int id, int &sock, int sex)
{

}
