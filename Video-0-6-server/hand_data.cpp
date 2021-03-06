#include "hand_data.h"
#include <unistd.h>
#include <string.h>
#include <getjson.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <stdio.h>

#define BUF_SIZE 1024

Hand_Data::Hand_Data()
{

}
void Hand_Data::handing(int clnt_sock)
{
    char message[BUF_SIZE];
    char c_username[BUF_SIZE/2];
    char c_password[BUF_SIZE/2];

    char re_success[BUF_SIZE]={"0"};//登录成功
    char re_fial_pwd[BUF_SIZE]={"-1"};//登录时的用户正确但密码错误
    char re_fial_user[BUF_SIZE]={"-2"};//登录的用户名不存在
    char re_fial_register[BUF_SIZE] = {"-3"};//注册的用户名存在

    memset(message, 0, BUF_SIZE);//清除原来的数据
    memset(c_username, 0, BUF_SIZE/2);//清除原来的数据
    memset(c_password, 0, BUF_SIZE/2);//清除原来的数据

    read(clnt_sock, message, BUF_SIZE);
    std::cout<<"message is: "<<message<<std::endl;
    std::cout<<"message[0] is: "<<message[0]<<std::endl;
    int size=1; //message的大小
    int n=0;  //message[0]~message[n]是username
    int m = 0;//message之后的都是password


    while (message[size]) {
        if(message[size] == '\n' && message[size+1]){
            for(n=0; n<size-1; n++){
                c_username[n] = message[n+1];
            }
        }
        size++;
    }//得到传输过来的用户名

    for(int j=n+2; j<size; j++){
        c_password[m] = message[j];
        m++;
    }//得到传输过来的密码

    std::cout<<"c_username is: "<<c_username<<std::endl;
    std::cout<<"c_password is: "<<c_password<<std::endl;

    DataBase database;
    if(!database.createConection("UserTable")){
        std::cout<<"创建不成功"<<std::endl;
    }
//    if(!database.userInsert(1, "gt", "12345","abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.createConection("VideoTable")){
//        std::cout<<"创建不成功"<<std::endl;
//    }
//    if(!database.videoInsert(1,"rtmp://127.0.0.1/vod/01.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "ace")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(2,"rtmp://127.0.0.1/vod/02.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "ace")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(3,"rtmp://127.0.0.1/vod/03.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(4,"rtmp://127.0.0.1/vod/04.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "bdc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(5,"rtmp://127.0.0.1/vod/05.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "def")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(6,"rtmp://127.0.0.1/vod/06.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "adb")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(7,"rtmp://127.0.0.1/vod/07.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(8,"rtmp://127.0.0.1/vod/08.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "bsc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(9,"rtmp://127.0.0.1/vod/09.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "bca")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(10,"rtmp://127.0.0.1/vod/10.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "bcd")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(11,"rtmp://127.0.0.1/vod/11.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(12,"rtmp://127.0.0.1/vod/12.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
    database.userUpdate("gt", "u_introduce", "my name is GT.");

//    database.deleteById("UserTable", 2);
//    database.deleteById("UserTable", 3);
//    database.deleteById("UserTable", 4);
//    database.deleteById("UserTable", 5);
//    database.deleteById("UserTable", 6);

    User userdata = database.UserSearch(c_username);

    //message[0]是标识位，0表示登录，1表示注册
    if(message[0] == '0'){
        if(database.isUserSearch(c_username)){
            if(compare(userdata, c_username, c_password)){
                write(clnt_sock, re_success, BUF_SIZE);
                sendUserFile(clnt_sock, c_username);
                sendVideoFile(clnt_sock);
            }else
                write(clnt_sock, re_fial_pwd, BUF_SIZE);//用户登录时密码错误
        }else
            write(clnt_sock, re_fial_user, BUF_SIZE);//登录时没有该用户名
    }
    if(message[0] == '1')
    {
        std::cout<<"进入注册"<<std::endl;

//        bool b=database.isUserSearch(c_username);
//        std::cout<<"返回值:"<<b<<std::endl;
        if(database.isUserSearch(c_username)){
            std::cout<<"存在该用户"<<std::endl;
            write(clnt_sock, re_fial_register, BUF_SIZE);

        }else{
            std::cout<<"不存在该用户"<<std::endl;
            if(!database.userInsert(7,c_username, c_password,"cba")){//将该用户写入数据库
                std::cout<<"插入不成功"<<std::endl;
            }


            std::cout<<"插入用户"<<std::endl;
            write(clnt_sock, re_success, BUF_SIZE);//回传数据
            sendUserFile(clnt_sock, c_username);
            sendVideoFile(clnt_sock);
        }
    }

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
void Hand_Data::sendUserFile(int clnt_sock, char* username)
{
    GetJson json;
    std::string message;
    char mes[BUF_SIZE];
    message = json.getUserInfo(username);
    strcpy(mes, message.c_str());
    write(clnt_sock, mes ,BUF_SIZE);
}
void Hand_Data::sendVideoFile(int clnt_sock)
{
    GetJson json;
    std::string message;
    message = json.GetTableJson("VideoTable");
    int send_length = message.length();

    char mes[send_length];
//    mes[0]=send_length;
//    write(clnt_sock, mes, 4);
//    std::cout<<"mes[0] is: "<<mes[0]<<std::endl;
//    std::cout<<"mes is: "<<mes<<std::endl;
//    std::cout<<message<<std::endl;
    strcpy(mes, message.c_str());
//    std::cout<<mes<<std::endl;
    write(clnt_sock, mes ,send_length);
    std::cout<<"传完"<<std::endl;
//    while(send_length<length){
//        message = json.getTableContent("VideoTable");
//        std::cout<<message<<std::endl;
//        strcpy(mes, message.c_str());
//        write(clnt_sock, &mes ,BUF_SIZE);
//        send_length+=1024;
//    }
}
