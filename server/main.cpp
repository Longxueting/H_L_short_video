#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <vector>
#include "json/json.h"
#include <fstream>
#include <cstdlib>
#include <mysql/mysql.h>
#include <QJsonObject>
#include "getjson.h"

#define BUF_SIZE 10240

using namespace std;

void error_handling(char * message);

int main(int argc, char* argv[])
{
    int serv_sock, clnt_sock;
    int i;

   string message;
   char mes[BUF_SIZE];

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    serv_sock=socket(PF_INET, SOCK_STREAM,0);
    if(serv_sock==-1)
        error_handling("socket() error");

    char *port="9190";

    memset(&serv_adr, 0, sizeof (serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(port));

    GetJson json;
    message = json.getTableContent("UserTable");

    cout<<"message: "<<message<<endl;

    strcpy(mes, message.c_str());

    cout<<"mes: "<<mes<<endl;

    if(bind(serv_sock,(struct sockaddr*)&serv_adr,sizeof (serv_adr))==-1)
        error_handling("bind() error");

    if(listen(serv_sock,5)==-1)
        error_handling("listen() error");

    clnt_adr_sz = sizeof (clnt_adr);

    for(i=0; i<5; i++){
        clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        if(clnt_sock==-1)
            error_handling("accept() error");
        else
            printf("Connected clinet %d \n", i+1);

        write(clnt_sock, &mes ,BUF_SIZE);
    }

    close(clnt_sock);
    close(serv_sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
