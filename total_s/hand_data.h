#ifndef HAND_DATA_H
#define HAND_DATA_H

#include "database.h"

class Hand_Data
{
public:
    Hand_Data();
    void handing(int clnt_sock);
    bool compare(User u, char *username, char *password);
    void sendwenjian(int clnt_sock);
};

#endif // HAND_DATA_H
