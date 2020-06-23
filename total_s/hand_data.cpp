#include "hand_data.h"
#include <unistd.h>
#include <string.h>
#include <getjson.h>
#include <iostream>

#define BUF_SIZE 1024

Hand_Data::Hand_Data()
{

}
void Hand_Data::handing(int clnt_sock)
{
    char message[BUF_SIZE];
    char c_username[BUF_SIZE/2];
    char c_password[BUF_SIZE/2];

    char re_success[BUF_SIZE]={"success!"};
    char re_fial[BUF_SIZE]={"not success!"};

    memset(message, 0, BUF_SIZE);//清除原来的数据
    memset(c_username, 0, BUF_SIZE/2);//清除原来的数据
    memset(c_password, 0, BUF_SIZE/2);//清除原来的数据

    read(clnt_sock, message, BUF_SIZE);

    int size=0; //message的大小
    int n;  //message[0]~message[n]是username
    int m = 0;//message之后的都是password

    while (message[size]) {
        if(message[size] == '\n' && message[size+1]){
            for(n=0; n<size; n++){
                c_username[n] = message[n];
            }
        }
        size++;
    }

    for(int j=n+1; j<size; j++){
        c_password[m] = message[j];
        m++;
    }

    DataBase database;
    if(!database.createConection("UserTable")){
        std::cout<<"创建不成功"<<std::endl;
    }
//    if(!database.userInsert(1, "gt", "12345")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
    User userdata = database.UserSearch(c_username);

    if(compare(userdata, c_username, c_password)){
        write(clnt_sock, re_success, BUF_SIZE);
        sendwenjian(clnt_sock);
    }
    else
        write(clnt_sock, re_fial, BUF_SIZE);

}

bool Hand_Data::compare(User u, char *username, char *password)
{

    QByteArray sr_u = u.username.toLocal8Bit();
    int len_u = sr_u.length();
    char *username_data = new char[len_u+2];
    username_data[len_u]=username_data[len_u+1]=0;
    strcpy(username_data, sr_u.data());

    QByteArray sr_p = u.password.toLocal8Bit();
    int len_p = sr_p.length();
    char *password_data = new char [len_p+2];
    password_data[len_p]=password_data[len_p+1]=0;
    strcpy(password_data, sr_p.data());

//    std::cout<<"database username_data: "<<username_data<<std::endl;
//    std::cout<<"database password_data: "<<password_data<<std::endl;

    if(strcmp(username_data,username)==0&&strcmp(password_data, password)==0)
        return true;
    else
        return false;

}
void Hand_Data::sendwenjian(int clnt_sock)
{
    GetJson json;
    std::string message;
    char mes[BUF_SIZE];
    message = json.getTableContent("UserTable");
    strcpy(mes, message.c_str());
    write(clnt_sock, &mes ,BUF_SIZE);
}
