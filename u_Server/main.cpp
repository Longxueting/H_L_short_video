#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "login.h"
#include <iostream>
#include "database.h"


#define BUF_SIZE 10240

void error_handling(char * message);
bool compar(User u, char *username, char *password);

int main(int argc, char* argv[])
{
    int serv_sock, clnt_sock;
    char message[BUF_SIZE];
    int i;
    int size=0; //message的大小
    int n;  //message[0]~message[n]是username

    int m = 0;//message之后的都是password
    char c_username[BUF_SIZE/2];
    char c_password[BUF_SIZE/2];

    char re_success[BUF_SIZE]={"success!"};
    char re_fial[BUF_SIZE]={"not success!"};

    Database database;
    if(!database.createConection("UserTable")){
        std::cout<<"创建不成功"<<std::endl;
    }

//    if(!database.userInsert(12, "gongting", "12345")){
//        std::cout<<"插入不成功"<<std::endl;
//    }

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    Login *user = new Login();

    user->setusername("gongting");
    user->setpassword("12345");

//    if(argc != 2){
//        printf("Usage: %s <port>\n",argv[0]);
//        exit(1);
//    }
    char *port="9190";
    serv_sock=socket(PF_INET, SOCK_STREAM,0);
    if(serv_sock==-1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof (serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(port));

    if(bind(serv_sock,(struct sockaddr*)&serv_adr,sizeof (serv_adr))==-1)
        error_handling("bind() error");

    if(listen(serv_sock,5)==-1)
        error_handling("listen() error");

    clnt_adr_sz = sizeof (clnt_adr);

    for(i=0; i<5; i++){
        size=0;
        n=0;
        m=0;
        clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        if(clnt_sock==-1)
            error_handling("accept() error");
        else
            printf("Connected clinet %d \n", i+1);

        memset(message, 0, BUF_SIZE);//清除原来的数据
        memset(c_username, 0, BUF_SIZE/2);//清除原来的数据
        memset(c_password, 0, BUF_SIZE/2);//清除原来的数据
        //将数据读取到message
        read(clnt_sock, message, BUF_SIZE);

        while (message[size]) {
            if(message[size] == '\n' && message[size+1]){
                for(n=0; n<size; n++){
                    c_username[n] = message[n];
                }
            }
            size++;
        }

        for(int j=n+1; j<size-1; j++){
            c_password[m] = message[j];
            m++;
        }


        User userdata = database.UserSearch("gongting");

//        int r=user->compared(c_username, c_password);
//        if(r==1)
//            write(clnt_sock, re_success, BUF_SIZE);
//        else
//            write(clnt_sock, re_fial, BUF_SIZE);

        if(compar(userdata, c_username, c_password))
            write(clnt_sock, re_success, BUF_SIZE);
        else
            write(clnt_sock, re_fial, BUF_SIZE);

        close(clnt_sock);
    }
//    delete user;
    close(serv_sock);
    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

bool compar(User u, char *username, char *password)
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

    if(username_data==username&&password_data==password)
        return true;
    else
        return false;
//    std::cout<<"username_data: "<<username_data<<std::endl;
}
