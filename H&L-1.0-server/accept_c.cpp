#include "accept_c.h"
#include <iostream>
#include <unistd.h>

Accept_C::Accept_C(int serv_sock)
{
    m_serv_sock=serv_sock;
    m_clnt_adr_sz = sizeof(m_clnt_adr);
}
void Accept_C::accept_client()
{
    int i=0;
    pid_t pid;
    while(1){
        m_clnt_sock=accept(m_serv_sock,(struct sockaddr*)&m_clnt_adr, &m_clnt_adr_sz);
        if(m_clnt_sock==-1){
            std::cout<<"accept() error"<<std::endl;
            return;
        }
        else
            printf("链接了第 %d 个用户... \n", i+1);
        i++;
        pid = fork();
        if(pid == 0){
            m_hand_data->handing(m_clnt_sock);
            close(m_clnt_sock);
        }else{
            close(m_clnt_sock);
        }
    }
//    close(m_clnt_sock);
    close(m_serv_sock);
}
int Accept_C::get_clnt_sock()
{
    return m_clnt_sock;
}
