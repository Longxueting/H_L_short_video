#include "client.h"
#include <iostream>
#include "conecting_s.h"

Client::Client()
{

}

int Client::sendU(QString qusername, QString qpassword)
{
    //把QString转为char *
    QByteArray sr_u = qusername.toLocal8Bit();
    int len_u = sr_u.length();
    char *c_username = new char[len_u+2];
    c_username[len_u] = c_username[len_u+1]=0;
    strcpy(c_username, sr_u.data());

    std::cout<<"c_nername is: "<<c_username<<std::endl;

    QByteArray sr_p = qpassword.toLocal8Bit();
    int len_p = sr_p.length();
    char *c_password = new char[len_p+2];
    c_password[len_p] = c_password[len_p+1]=0;
    strcpy(c_password, sr_p.data());

    std::cout<<"c_password is: "<<c_password<<std::endl;

    Conecting_S *clientt = new Conecting_S();
    clientt->connecting(c_username, c_password);

    delete clientt;
    return 0;
}
