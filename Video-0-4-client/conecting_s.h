#ifndef CONECTING_S_H
#define CONECTING_S_H

#include <iostream>
#include "user.h"

class Conecting_S
{
public:
    Conecting_S();
    User* connecting(std::string username, std::string password, int &re);
};

#endif // CONECTING_S_H
