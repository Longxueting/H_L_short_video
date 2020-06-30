#ifndef CONECTING_S_H
#define CONECTING_S_H

#include <iostream>
#include "user.h"
#include "hand_data.h"

class Conecting_S
{
public:
    Conecting_S();
    User* connecting(std::string username, std::string password, int &re, int flag);

    void sendID(int id);
    void sendIntroduce(int id, char * introduce);
    void sendSex(int id, int sex);

private:
    Hand_Data m_handData;
    int m_sock;
};

#endif // CONECTING_S_H
