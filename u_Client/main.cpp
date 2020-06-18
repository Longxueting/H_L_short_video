#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock;

    char message[BUF_SIZE];

    std::string username;
    std::string password;

    char c_username[BUF_SIZE/2];
    char c_password[BUF_SIZE/2];

    char revice[BUF_SIZE];

    int str_len, recv_len, recv_cnt;
    int k;
    struct sockaddr_in serv_adr;

//    if(argc!=3){
//        printf("Usage : %s<IP> <port>\n", argv[0]);
//        exit(1);
//    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock==-1)
        std::cout<<"error"<<std::endl;

    char *ip = "127.0.0.1";
    char *port = "9190";
    memset(&serv_adr, 0, sizeof (serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(ip);
    serv_adr.sin_port=htons(atoi(port));

    if(connect(sock, (struct sockaddr *)&serv_adr, sizeof (serv_adr))==-1)
        std::cout<<"error"<<std::endl;
    else
        puts("Conected............");

    std::cout<<"username: ";
    fgets(message, BUF_SIZE/2, stdin);
    std::cout<<"password: ";
    fgets(c_password, BUF_SIZE/2, stdin);
    strcat(message, c_password);

    write(sock, message, strlen(message));//向服务器传输数据

    read(sock, revice, BUF_SIZE);//读取服务器的数据

    std::cout<<revice<<std::endl;

    close(sock);
    return 0;
}

