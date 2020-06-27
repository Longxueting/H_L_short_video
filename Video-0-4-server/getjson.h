#ifndef GETJSON_H
#define GETJSON_H
#include <iostream>
#include <string>

class GetJson{
public:
    GetJson();
    std::string getTableContent(std::string tablemame);
    ~GetJson();
};

#endif // GETJSON_H
