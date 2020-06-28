#ifndef BIND_C_H
#define BIND_C_H

#include <arpa/inet.h>
class Bind_C
{
public:
    Bind_C();
    void assigin_address();
    void listen_client();
    int get_serv_socke();

private:
    int m_serv_sock;//socket()函数返回的文件描述符
    struct sockaddr_in m_serv_adr;//存有地址信息的结构体
    char *m_port;//端口号
};

#endif // BIND_C_H
