#ifndef Database_H
#define Database_H

//#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
//#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QMessageBox>
#include <string>
#include <iostream>
using namespace std;

struct User{
    int id;
    QString username;
    QString password;
    QString img;
    int sex;
    int age;
    QString introduce;
    QString local;
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
};

class Database{
public:
    bool createConection(string table);//创建一个链接
    bool createTable(string table);       //创建数据库表
    bool videoInsert(int videoid,char* videoURL,char* videoDescribe,char* author,char* author_img,char* time,char* tag);
    bool userInsert(int userid,char* username,char* password,char* tag);            //插入数据
    bool islike(int userid,int videoid);
    bool userlikeInsert(int userid,int videoid);
    bool deleteUserLike(int userid,int videoid);
    bool queryAll();          //查询所有信息
    bool videoUpdate(int id,string key,char* newdata);  //更新
    bool userUpdate(char* username,string key,char* newdata);
    bool deleteById(string table,int id);  //删除
    bool sortById();          //排序
    Video videoSearch(int id);
    User UserSearch(string username);
};

#endif // Database_H
