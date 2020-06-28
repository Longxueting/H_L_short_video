#ifndef HAND_DATA_H
#define HAND_DATA_H

#include "user.h"

class Hand_Data
{
public:
    Hand_Data();
    User* handUser(int sock, int &re);
    void handVideo(int sock);
};

#endif // HAND_DATA_H
