#ifndef GETJSON_H
#define GETJSON_H
#include <iostream>
#include <string>

using namespace std;
class GetJson{
public:
    GetJson();
    string GetTableJson(string tablemame);//返回tablename的所有信息.
    void GetOriginalVideo(string author);
    void getTagJson(string);
    string getUserInfo(char *username);
    ~GetJson();
};

#endif // GETJSON_H
