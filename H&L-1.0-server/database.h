#ifndef DATABASE_H
#define DATABASE_H

#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include <string>
#include <iostream>

struct User{
    int id;
    QString username;
    QString password;
    QString img;
    int sex;
    int age;
    QString introduce;
    QString local;
    QString tags;
};

struct Video{
    int v_id;
    QString url;
    int like_num;
    int comment_num;
    int transmit_num;
    QString describe;
    QString author;
    QString author_img;
    QString time;
    QString tags;
};

class DataBase
{
public:
    bool createConection(std::string table);//创建一个链接
    bool videoInsert(int videoid,char* videoURL,char* videoDescribe,char* author,char* author_img,char* time,char* tag);
    bool userInsert(char* username,char* password,char* tag);             //插入数据
    bool islike(int userid,int videoid);
    bool userlikeInsert(int userid,int videoid);
    bool deleteUserLike(int userid,int videoid);
//    bool queryAll();          //查询所有信息
    bool videoUpdate(int id,std::string key,char* newdata);  //更新
    bool userUpdate(char* username,std::string key,char* newdata);
    bool userUpdataById(int userid,std::string key,char* newdata);
    bool deleteById(std::string table,int id);  //删除
    bool sortById();          //排序
    Video videoSearch(int id);
    User UserSearch(std::string username);
    bool isUserSearch(char *username);
    bool isUserId(int userId);
    int getRandom();
};

#endif // DATABASE_H
