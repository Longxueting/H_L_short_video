#include "conecting_s.h"
#include "uandp.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <QByteArray>
#include <fstream>
#include <sstream>
#include "hand_data.h"

#define BUF_SIZE 1024
using namespace std;
Conecting_S::Conecting_S()
{

}
User* Conecting_S::connecting(std::string username, std::string password, int &re, int flag)
{
    int sock;

    char message[BUF_SIZE];

    char c_username[BUF_SIZE/2];
    char c_password[BUF_SIZE/2];

    stringstream ss;
    ss<<flag;
    string flags = ss.str();

    //string转为char数组
    username += "\n";
    strcpy(c_username, username.c_str());
    strcpy(c_password, password.c_str());

    strcpy(message,flags.c_str());//第一位放标识位
    strcat(message, c_username);//追加
    strcat(message, c_password);//追加

    std::cout<<"GT message id: "<<message<<std::endl;

    int i=0;
    while (message[i]) {
        std::cout<<message[i]<<std::endl;
        i++;
    }
//    std::cout<<message<<std::endl;

//    char *receive = new char[BUF_SIZE+1];
    char receive[BUF_SIZE];

    struct sockaddr_in serv_adr;

    m_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(m_sock==-1)
        std::cout<<"error"<<std::endl;

    char *ip = "192.168.43.210";
    char *port = "9190";

    memset(&serv_adr, 0, sizeof (serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(ip);
    serv_adr.sin_port=htons(atoi(port));

    if(connect(m_sock, (struct sockaddr *)&serv_adr, sizeof (serv_adr))==-1){
        std::cout<<"连接错误"<<std::endl;
        return nullptr;
    }
    else
        puts("Conected............");

//    stringstream ss;
//    ss<<flag;
//    string s1 = ss.str();

//    write(sock, &s1, s1.length());//写入便标志位
    write(m_sock, message, strlen(message));//向服务器传输数据

    User *user=nullptr;
//    Hand_Data handdata;

    user = m_handData.handUser(m_sock,re);

    m_handData.handVideo(m_sock);
//    m_handData.handImg(sock);

    close(sock);

    return user;
}

void Conecting_S::sendID(int id)
{
//    m_handData.handImg(id, m_sock);
}

void Conecting_S::sendIntroduce(int id, char *introduce)
{
    m_handData.handIntroduce(id, m_sock, introduce);
}

void Conecting_S::sendSex(int id, int sex)
{
    m_handData.handSex(id, m_sock, sex);
}
