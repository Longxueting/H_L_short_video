#include "hand_data.h"
#include <unistd.h>
#include <string.h>
#include <getjson.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <QDebug>
#include <sstream>
#include <fstream>

#define BUF_SIZE 1024
#define MAXLINE 4096

Hand_Data::Hand_Data()
{

}
void Hand_Data::handing(int& clnt_sock)
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

    DataBase database;
    if(!database.createConection("UserTable")){
        std::cout<<"创建不成功"<<std::endl;
    }
    User userdata;
    while (read(clnt_sock, message, BUF_SIZE)) {
//        cout<<message<<endl;

        if(message[0] =='0'||message[0] == '1'){
            getUandP(message, c_username, c_password);
            userdata = database.UserSearch(c_username);
//            cout<<"c_username is: "<<c_username<<endl;
//            cout<<"c_password is: "<<c_password<<endl;
//            qDebug()<<"userdata.username"<<userdata.username;
//            qDebug()<<"userdata.password"<<userdata.password;
        }

        if(message[0] == '0'){
            cout<<"登录"<<endl;
            cout<<"database.isUserSearch(c_username) is: "<<database.isUserSearch(c_username)<<endl;
            if(database.isUserSearch(c_username)){
                cout<<"compare(userdata, c_username, c_password)"<<compare(userdata, c_username, c_password)<<endl;
                if(compare(userdata, c_username, c_password)){
                    write(clnt_sock, re_success, BUF_SIZE);
                    sendUserFile(clnt_sock, c_username);
                    sendVideoFile(clnt_sock);

//                    wait(clnt_sock);
                }else
                    write(clnt_sock, re_fial_pwd, BUF_SIZE);//用户登录时密码错误
            }else
                write(clnt_sock, re_fial_user, BUF_SIZE);//登录时没有该用户名
        } else
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
                if(!database.userInsert(c_username, c_password,"cba")){//将该用户写入数据库
                    std::cout<<"插入不成功"<<std::endl;
                }


                std::cout<<"插入用户"<<std::endl;
                write(clnt_sock, re_success, BUF_SIZE);//回传数据
                sendUserFile(clnt_sock, c_username);
                sendVideoFile(clnt_sock);
//                wait(clnt_sock);
            }
        }else
        if(message[0] == 'a'){
            cout<<"进入图片"<<endl;
            char idC[BUF_SIZE];
            strncpy(idC, message+1, 5);
            cout<<"idC is : "<<idC<<endl;
            int id = stoi(idC);
            cout<<"id is :"<<id<<endl;
            sendImg(id,clnt_sock);
            memset(message, 0, BUF_SIZE);
            std::cout<<"图片传完"<<std::endl;
        }else
        if(message[0] == 'b'){
            cout<<"message is :"<<message<<endl;
            cout<<"进入简介"<<endl;
            char idC[BUF_SIZE];
            strncpy(idC, message+1, 5);
            cout<<"idC is : "<<idC<<endl;
            int id = stoi(idC);
            cout<<"id is :"<<id<<endl;
            char introduce[BUF_SIZE];
            strncpy(introduce, message+6, BUF_SIZE);
            std::cout<<"introduce is :"<<introduce<<endl;
            insertIntroduce(id, database, introduce);

        }
//            else
//        {
//            cout<<"没有这个类型"<<endl;
//            cout<<'message: '<<message<<endl;
//        }

    }

//    read(clnt_sock, message, BUF_SIZE);
//    std::cout<<"message is: "<<message<<std::endl;
//    std::cout<<"message[0] is: "<<message[0]<<std::endl;
//    int size=1; //message的大小
//    int n=0;  //message[0]~message[n]是username
//    int m = 0;//message之后的都是password


//    while (message[size]) {
//        if(message[size] == '\n' && message[size+1]){
//            for(n=0; n<size-1; n++){
//                c_username[n] = message[n+1];
//            }
//        }
//        size++;
//    }//得到传输过来的用户名

//    for(int j=n+2; j<size; j++){
//        c_password[m] = message[j];
//        m++;
//    }//得到传输过来的密码

//    std::cout<<"c_username is: "<<c_username<<std::endl;
//    std::cout<<"c_password is: "<<c_password<<std::endl;

//    DataBase database;
//    if(!database.createConection("UserTable")){
//        std::cout<<"创建不成功"<<std::endl;
//    }
//    if(!database.userInsert(1, "gt", "12345","abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.createConection("VideoTable")){
//        std::cout<<"创建不成功"<<std::endl;
//    }
//    if(!database.videoInsert(1,"rtmp://192.168.43.210/vod/01.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "ace")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(2,"rtmp://192.168.43.210/vod/02.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "ace")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(3,"rtmp://192.168.43.210/vod/03.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(4,"rtmp://192.168.43.210/vod/04.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "bdc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(5,"rtmp://192.168.43.210/vod/05.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "def")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(6,"rtmp://192.168.43.210/vod/06.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "adb")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(7,"rtmp://192.168.43.210/vod/07.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(8,"rtmp://192.168.43.210/vod/08.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "bsc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(9,"rtmp://192.168.43.210/vod/09.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "bca")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(10,"rtmp://192.168.43.210/vod/10.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "bcd")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(11,"rtmp://192.168.43.210/vod/11.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    if(!database.videoInsert(12,"rtmp://192.168.43.210/vod/12.mp4","aaaa","bbb","/root/receiver/","2020/06/26/", "abc")){
//        std::cout<<"插入不成功"<<std::endl;
//    }
//    database.userUpdate("gt", "u_introduce", "my name is GT.");

//    database.deleteById("UserTable", 2);
//    database.deleteById("UserTable", 3);
//    database.deleteById("UserTable", 4);
//    database.deleteById("UserTable", 5);
//    database.deleteById("UserTable", 6);

//    User userdata = database.UserSearch(c_username);

    //message[0]是标识位，0表示登录，1表示注册
//    if(message[0] == '0'){
//        if(database.isUserSearch(c_username)){
//            if(compare(userdata, c_username, c_password)){
//                write(clnt_sock, re_success, BUF_SIZE);
//                sendUserFile(clnt_sock, c_username);
//                sendVideoFile(clnt_sock);
//                wait(clnt_sock);
//            }else
//                write(clnt_sock, re_fial_pwd, BUF_SIZE);//用户登录时密码错误
//        }else
//            write(clnt_sock, re_fial_user, BUF_SIZE);//登录时没有该用户名
//    }
//    if(message[0] == '1')
//    {
//        std::cout<<"进入注册"<<std::endl;

////        bool b=database.isUserSearch(c_username);
////        std::cout<<"返回值:"<<b<<std::endl;
//        if(database.isUserSearch(c_username)){
//            std::cout<<"存在该用户"<<std::endl;
//            write(clnt_sock, re_fial_register, BUF_SIZE);

//        }else{
//            std::cout<<"不存在该用户"<<std::endl;
//            if(!database.userInsert(c_username, c_password,"cba")){//将该用户写入数据库
//                std::cout<<"插入不成功"<<std::endl;
//            }


//            std::cout<<"插入用户"<<std::endl;
//            write(clnt_sock, re_success, BUF_SIZE);//回传数据
//            sendUserFile(clnt_sock, c_username);
//            sendVideoFile(clnt_sock);
//            wait(clnt_sock);
//        }
//    }
//    memset(message, 0, BUF_SIZE);
//    read(clnt_sock, message, BUF_SIZE);
//    int id = stoi(message);
//    sendImg(id,clnt_sock);

    close(clnt_sock);

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

    std::cout<<"database username_data: "<<username_data<<std::endl;
    std::cout<<"database password_data: "<<password_data<<std::endl;

    if(strcmp(username_data,username)==0&&strcmp(password_data, password)==0)
        return true;
    else
        return false;

}
void Hand_Data::sendUserFile(int& clnt_sock, char* username)
{
    GetJson json;
    std::string message;
    char mes[BUF_SIZE];
    message = json.getUserInfo(username);
    strcpy(mes, message.c_str());
    strcat(mes, "\0");
    write(clnt_sock, mes ,BUF_SIZE);
}
void Hand_Data::sendVideoFile(int& clnt_sock)
{
    GetJson json;

//    std::cout<<"啦啦啦啦"<<std::endl;

    std::string message;
    message = json.GetTableJson("VideoTable");
    int send_length = message.length();
//    int time = send_length/BUF_SIZE;

//    std::cout<<"send_length = "<<send_length<<std::endl;
//    std::cout <<"time = "<<time<<std::endl;

//    std::string timesting = std::to_string(time);

//    char mestime[timesting.length()];//存长度
//    strcpy(mestime, timesting.c_str());
//    std::cout <<"mestime = "<<mestime<<std::endl;
//    write(clnt_sock, mestime, BUF_SIZE);

//    char message[send_length];
//    strcpy(message, messagejson.c_str());
//    std::cout<<"message = "<<message<<std::endl;
//    write(clnt_sock, message, send_length);



    char mes[send_length];
//    mes[0]=send_length;
//    write(clnt_sock, mes, 4);
//    std::cout<<"mes[0] is: "<<mes[0]<<std::endl;
//    std::cout<<"mes is: "<<mes<<std::endl;
//    std::cout<<message<<std::endl;

    strcpy(mes, message.c_str());


//    std::cout<<mes[send_length+1]<<std::endl;

    write(clnt_sock, mes , send_length);
    std::cout<<"传完"<<std::endl;

//    while(send_length<length){
//        message = json.getTableContent("VideoTable");
//        std::cout<<message<<std::endl;
//        strcpy(mes, message.c_str());
//        write(clnt_sock, &mes ,BUF_SIZE);
//        send_length+=1024;
    //    }
}
void Hand_Data::sendImg(int id, int& clnt_sock)
{


    string idS = to_string(id);
    FILE *fq;
    char  buffer[MAXLINE];
    int len;


   string fileString = "/run/media/root/study/H&L/tupian/"+idS+".jpg";

   stringstream ss;
   ifstream in(fileString,ios::binary);
   ss<<in.rdbuf();

   string s = ss.str();

   cout<<"string s size: "<<s.size();
//   ss>>s;

//   char c[s.length()];

//   strcpy(c, s.c_str());

   write(clnt_sock, s.data(), s.size());


//   char file[BUF_SIZE];
//   strcpy(file, fileString.c_str());
//    if( ( fq = fopen(file,"rb") ) == nullptr ){//rb只读打开一个二进制文件，只允许读数据
//        printf("File open.\n");
//        close(clnt_sock);
//        exit(1);
//    }
//    bzero(buffer,sizeof(buffer));
//    while(!feof(fq)){
//        len = fread(buffer, 1, sizeof(buffer), fq);
//        std::cout<<"len = "<<len<<std::endl;
//        if(len != write(clnt_sock, buffer, len)){
//            printf("write.\n");
//            break;
//        }
//    }
//    fclose(fq);
//    close(clnt_sock);
}

void Hand_Data::wait(int &clnt_sock)
{
    cout<<"进入wait"<<endl;
    char message[BUF_SIZE];
    memset(message, 0, BUF_SIZE);
    char idC[BUF_SIZE];
    string s;
    while (1) {
        read(clnt_sock, message, BUF_SIZE);
        if(message[0] == 'a'){
            strncpy(idC, message+1, 6);
            cout<<"idC is : "<<idC<<endl;
            int id = stoi(idC);
            cout<<"id is :"<<id<<endl;
            sendImg(id,clnt_sock);
            memset(message, 0, BUF_SIZE);
            std::cout<<"图片传完"<<std::endl;
        }
    }
}

void Hand_Data::getUandP(char *message ,char *c_username, char *c_password)
{
    int size=1;
    int n=0;
    int m=0;
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
}

bool Hand_Data::insertIntroduce(int id, DataBase &database, char *introduce)
{
    return database.userUpdataById(id, "u_introduce", introduce);
}
