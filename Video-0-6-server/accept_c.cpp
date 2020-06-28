#include "accept_c.h"
#include <iostream>

Accept_C::Accept_C(int serv_sock)
{
    m_serv_sock=serv_sock;
    m_clnt_adr_sz = sizeof(m_clnt_adr);
}
void Accept_C::accept_client()
{
    int i=0;
    for(i=0; i<5; i++){
        m_clnt_sock=accept(m_serv_sock,(struct sockaddr*)&m_clnt_adr, &m_clnt_adr_sz);
        if(m_clnt_sock==-1){
            std::cout<<"accept() error"<<std::endl;
            return;
        }
        else
            printf("链接了第 %d 个用户... \n", i+1);

        m_hand_data->handing(m_clnt_sock);
    }

}
int Accept_C::get_clnt_sock()
{
    return m_clnt_sock;
}
