#include "client.h"

Client::Client()
{
    m_bind=Bind_C();
    m_bind.assigin_address();
    m_bind.listen_client();
    m_serv_socke=m_bind.get_serv_socke();
    m_accept=new Accept_C(m_serv_socke);
    m_accept->accept_client();
}
