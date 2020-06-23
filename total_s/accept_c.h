#ifndef ACCEPT_C_H
#define ACCEPT_C_H

#include <arpa/inet.h>
#include "hand_data.h"

class Accept_C
{
public:
    Accept_C(int ser_sock);
    void accept_client();
    int get_clnt_sock();
private:
    struct sockaddr_in m_clnt_adr;
    socklen_t m_clnt_adr_sz;
    int m_serv_sock;
    int m_clnt_sock;
    Hand_Data *m_hand_data;
};

#endif // ACCEPT_C_H
