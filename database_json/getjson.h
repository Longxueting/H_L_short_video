#ifndef GETJSON_H
#define GETJSON_H
#include <iostream>
#include <string>

using namespace std;
class GetJson{
public:
    GetJson();
    void GetTableJson(string tablemame);
    void GetOriginalVideo(string author);
    void getTagJson(string);
    ~GetJson();
};

#endif // GETJSON_H
