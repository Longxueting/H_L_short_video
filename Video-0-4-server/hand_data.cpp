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

    char re_success[BUF_SIZE]={"0"};
    char re_fial[BUF_SIZE]={"-1"};

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
    database.userUpdate("gt", "u_introduce", "my name is gongting");

    User userdata = database.UserSearch(c_username);

    if(compare(userdata, c_username, c_password)){
        write(clnt_sock, re_success, BUF_SIZE);
        sendUserFile(clnt_sock);
        sendVideoFile(clnt_sock);
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
void Hand_Data::sendUserFile(int clnt_sock)
{
    GetJson json;
    std::string message;
    char mes[BUF_SIZE];
    message = json.getTableContent("UserTable");
    strcpy(mes, message.c_str());
    write(clnt_sock, mes ,BUF_SIZE);
}
void Hand_Data::sendVideoFile(int clnt_sock)
{
    GetJson json;
    std::string message;


    message = json.getTableContent("VideoTable");
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
