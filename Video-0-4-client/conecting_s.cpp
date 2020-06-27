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
#include "hand_data.h"

#define BUF_SIZE 1024
using namespace std;
Conecting_S::Conecting_S()
{

}
User* Conecting_S::connecting(std::string username, std::string password, int &re)
{
    int sock;

    char message[BUF_SIZE];

    char c_username[BUF_SIZE/2];
    char c_password[BUF_SIZE/2];

    //string转为char数组
    username += "\n";
    strcpy(message, username.c_str());
    strcpy(c_password, password.c_str());

    strcat(message, c_password);//追加

    int i=0;
    while (message[i]) {
        std::cout<<message[i]<<std::endl;
        i++;
    }
//    std::cout<<message<<std::endl;

//    char *receive = new char[BUF_SIZE+1];
    char receive[BUF_SIZE];

    struct sockaddr_in serv_adr;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock==-1)
        std::cout<<"error"<<std::endl;

    char *ip = "127.0.0.1";
    char *port = "9190";

    memset(&serv_adr, 0, sizeof (serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(ip);
    serv_adr.sin_port=htons(atoi(port));

    if(connect(sock, (struct sockaddr *)&serv_adr, sizeof (serv_adr))==-1){
        std::cout<<"连接错误"<<std::endl;
        return nullptr;
    }
    else
        puts("Conected............");

    write(sock, message, strlen(message));//向服务器传输数据

    User *user=nullptr;
    Hand_Data handdata;

    user = handdata.handUser(sock,re);
    handdata.handVideo(sock);

    close(sock);

    return user;
}
