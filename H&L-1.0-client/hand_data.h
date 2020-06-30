#ifndef HAND_DATA_H
#define HAND_DATA_H

#include "user.h"

class Hand_Data
{
public:
    Hand_Data();
    User* handUser(int &sock, int &re);
    void handVideo(int &sock);
    void handImg(int id, int &sock);
    void handIntroduce(int id, int &sock, char *introduce);
    void handSex(int id, int &sock, int sex);
};

#endif // HAND_DATA_H
