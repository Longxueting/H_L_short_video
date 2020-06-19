#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <fstream>
#include "json/json.h"

#define BUF_SIZE 1024

using namespace std;
int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_adr;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock==-1)
        std::cout<<"error"<<std::endl;

    char *ip="127.0.0.1";
    char *port="9190";

    memset(&serv_adr, 0, sizeof (serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(ip);
    serv_adr.sin_port=htons(atoi(port));

    if(connect(sock, (struct sockaddr *)&serv_adr, sizeof (serv_adr))==-1)
        std::cout<<"error"<<std::endl;
    else
        puts("Conected............");

    char message[BUF_SIZE];
    ofstream os;
    string tableName = "user.json";
    os.open( tableName.c_str() );

    read(sock, message ,BUF_SIZE);

    cout<<"message is : "<<message<<endl;
    os << message;
    os << flush;
    os.close();

    close(sock);
    return 0;

}
