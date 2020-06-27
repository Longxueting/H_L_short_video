#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h>
#include "bind_c.h"
#include "accept_c.h"

class Client
{
public:
    Client();
//    void f();
private:
    int m_serv_socke;//套接字
    int m_clnt_socke;//套接字
    Bind_C m_bind;
    Accept_C *m_accept;
};

#endif // CLIENT_H
