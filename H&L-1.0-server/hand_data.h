#ifndef HAND_DATA_H
#define HAND_DATA_H

#include "database.h"

class Hand_Data
{
public:
    Hand_Data();
    void handing(int& clnt_sock);
    bool compare(User u, char *username, char *password);
    void sendUserFile(int &clnt_sock, char *username);
    void sendVideoFile(int &clnt_sock);
    void sendImg(int id, int& clnt_sock);
    void wait(int &clnt_sock);
    void getUandP(char *message, char *username, char *password);
    bool insertIntroduce(int id, DataBase &database, char *introduce);
};

#endif // HAND_DATA_H
