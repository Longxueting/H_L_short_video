#include "bind_c.h"
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

Bind_C::Bind_C()
{
    this->m_serv_sock = socket(PF_INET, SOCK_STREAM,0);
    this->m_port={"9190"};
    memset(&m_serv_adr, 0, sizeof (m_serv_adr));
    m_serv_adr.sin_family = AF_INET;
    m_serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_serv_adr.sin_port = htons(atoi(m_port));
    int contain;//设置可重用
    setsockopt(m_serv_sock,SOL_SOCKET, SO_REUSEADDR, &contain, sizeof(int));
}
void Bind_C::assigin_address()
{
    if(bind(m_serv_sock, (struct sockaddr*)&m_serv_adr, sizeof(m_serv_adr))){
        std::cout<<"分配地址失败!"<<std::endl;
        return;
    }
    else
        std::cout<<"地址分配成功!"<<std::endl;
}
void Bind_C::listen_client()
{
    if(listen(m_serv_sock,5)==-1){
        std::cout<<"监听失败!"<<std::endl;
        return;
    }
    else
        std::cout<<"正在监听!"<<std::endl;
}
int Bind_C::get_serv_socke()
{
    return m_serv_sock;
}
