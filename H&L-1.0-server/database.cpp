#include "database.h"

using namespace std;

bool DataBase::createConection(string table){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("short_video");       //这里输入你的数据库名
    db.setUserName("root");
    db.setPassword("");   //这里输入你的密码
    if (!db.open()) {
        std::cout<<"无法打开数据库"<<std::endl;
        return false;
    }
    //下面来创建表
    // 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
    QSqlQuery query(db);
    // 使数据库支持中文
    query.exec("SET NAMES 'utf8'");
     //创建 course 表
    //创建 course 表
   if(table=="VideoTable"){
       query.exec("create table VideoTable (v_id int primary key, "
               "v_url varchar(100) not null, v_like_num int not null, v_comment_num int not null, v_transmit_num int not null, v_describe varchar(100) not null, v_author varchar(10) not null, v_author_img longblob not null, v_time varchar(20) not null,v_tag varchar(200))engine=InnoDB default charset=UTF8");
   }
   if(table=="UserTable"){
       query.exec("create table UserTable (u_id int primary key, "
                  "u_username varchar(20) not null, u_password varchar(30) not null, u_img longblob not null,u_sex int, u_age int, u_introduce varchar(200), u_local varchar(30), u_tag varchar(100))engine=InnoDB default charset=UTF8");
   }
    query.exec("create table user_video (u_id int not null, v_id int not null,foreign key(u_id) references UserTable(u_id),foreign key(v_id) references VideoTable(v_id),primary key(u_id,v_id))engine=InnoDB default charset=UTF8");
    return true;
}


bool DataBase::videoInsert(int videoid,char* videoURL,char*videoDescribe,char* author,char* author_img,char* time ,char* tag){
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command;
    command="insert into VideoTable(v_id,v_url,v_like_num,v_comment_num,v_transmit_num,v_describe,v_author,v_author_img,v_time,v_tag ) values("+to_string(videoid)+",'"+string(videoURL)+"',0,0,0,'"+videoDescribe+"','"+author+"','"+author_img+"','"+time+"','"+tag+"');";
    cout<<command<<endl;
    //query.exec();
    bool success=query.exec(command.c_str());
    if(!success)
    {
        QSqlError lastError=query.lastError();
        qDebug()<<lastError.driverText()<<QString(QObject::tr("视频信息表插入失败"));
        return false;
    }
    return true;
}

bool DataBase::userInsert(char* username, char* password,char* tag)
{
    int userid;
    srand((int)time(0));
//    userid=getRandom();
    while (1) {
        userid=getRandom();
        if(!isUserId(userid)){
            break;
        }
    }
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command;
    command="insert into UserTable(u_id,u_username,u_password,u_img,u_sex,u_age,u_introduce,u_local,u_tag) values("+to_string(userid)+",'"+username+"','"+password+"','头像地址',1,0,'','','"+tag+"');";
    cout<<command<<endl;
    //query.exec();
    bool success=query.exec(command.c_str());
    if(!success)
    {
        QSqlError lastError=query.lastError();
        qDebug()<<lastError.driverText()<<QString(QObject::tr("用户信息表插入失败"));
        return false;
    }
    return true;
}


bool DataBase::videoUpdate(int id, string key, char *newdata)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command;
    command="update VideoTable set "+key+"='"+string(newdata)+"' where v_id="+to_string(id)+";";
    cout<<command<<endl;
    query.prepare(command.c_str());
    if(!query.exec())
    {
        qDebug() << "数据更新失败！";
        return false;
    }
    return true;
}

bool DataBase::userUpdate(char *username, string key, char *newdata)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command;
    command="update UserTable set "+key+"='"+string(newdata)+"' where u_username='"+string(username)+"';";
    cout<<command<<endl;
    query.prepare(command.c_str());
    if(!query.exec())
    {
        qDebug() << "数据更新失败！";
        return false;
    }
    return true;
}

bool DataBase::userUpdataById(int userid, string key, char *newdata)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command;
    command="update UserTable set "+key+"='"+string(newdata)+"' where u_id='"+to_string(userid)+"';";
    cout<<command<<endl;
    query.prepare(command.c_str());
    if(!query.exec())
    {
        qDebug() << "数据更新失败！";
        return false;
    }
    return true;
}

bool DataBase::deleteById(string table,int id){
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command;
    if(table=="VideoTable")
        command=("delete from "+table+" where v_id ="+to_string(id));
    if(table=="UserTable")
        command=("delete from "+table+" where u_id ="+to_string(id));
    cout<<command<<endl;
    query.prepare(command.c_str());
    if(!query.exec())
    {
        qDebug() << "删除记录失败！";
        return false;
    }
    return true;
}

Video DataBase::videoSearch(int id)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    Video video;
    string command=("select *from VideoTable where v_id ="+to_string(id)+";");
    cout<<command<<endl;
    query.exec(command.c_str());
    while (query.next()) {
        video.v_id=query.value(0).toInt();
        video.url=query.value(1).toString();
        video.like_num=query.value(2).toInt();
        video.comment_num=query.value(3).toInt();
        video.transmit_num=query.value(4).toInt();
        video.describe=query.value(5).toString();
        video.author=query.value(6).toString();
        video.author_img=query.value(7).toString();
        video.time=query.value(8).toString();
//        for(int i=9;i<9;i++)
//            video.append(query.value(i).toString());
    }
    return video;
}

User DataBase::UserSearch(string username)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    User user;
    string command=("select *from UserTable where u_username ='"+username+"';");
    cout<<command<<endl;
    query.exec(command.c_str());
    while (query.next()) {
        user.id=query.value(0).toInt();
        user.username=query.value(1).toString();
        user.password=query.value(2).toString();
        user.img=query.value(3).toString();
        user.sex=query.value(4).toInt();
        user.age=query.value(5).toInt();
        user.introduce=query.value(6).toString();
        user.local=query.value(7).toString();
    }
    return user;
}

bool DataBase::isUserSearch(char *username)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    User user;
    string command=("select *from UserTable where u_username ='"+string(username)+"';");
    cout<<command<<endl;
    query.prepare(command.c_str());
    query.exec();
    query.next();
    string command1=("select *from UserTable where u_username ='"+string(username)+"';");
    cout<<command1<<endl;
    qDebug()<<query.value(1).toString();
    if(query.value(1).toString()==""){
        cout<<"不存在该用户"<<endl;
        return false;
    }
    return true;//找到返回true否则返回false
}

bool DataBase::islike(int userid, int videoid)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command=("select u_id,v_id from user_video where u_id ="+to_string(userid)+" and v_id="+to_string(videoid)+";");
    cout<<command<<endl;
    query.prepare(command.c_str());
    if(!query.exec()){
        cout<<"用户已经有对该视频点赞"<<endl;
        return true;
    }
    return false;
}
bool DataBase::deleteUserLike(int userid, int videoid)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command;
    command=("delete from user_video where u_id ="+to_string(userid)+" and v_id="+to_string(videoid)+";");
    cout<<command<<endl;
    query.prepare(command.c_str());
    if(!query.exec())
    {
        qDebug() << "删除记录失败！";
        return false;
    }
    return true;
}
bool DataBase::userlikeInsert(int userid, int videoid){
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command;
    command="insert into user_video(u_id,v_id) values("+to_string(userid)+","+to_string(videoid)+");";
    cout<<command<<endl;
    bool success=query.exec(command.c_str());
    if(!success)
    {
        QSqlError lastError=query.lastError();
        qDebug()<<lastError.driverText()<<QString(QObject::tr("点赞信息录入失败"));
        return false;
    }
    return true;

}
bool DataBase::isUserId(int userId)
{
    QSqlDatabase db=QSqlDatabase::database("short_video");
    QSqlQuery query(db);
    string command=("select u_id from UserTable where u_id ="+to_string(userId)+";");
    cout<<command<<endl;
    query.prepare(command.c_str());
    query.exec();
    query.next();

    qDebug()<<query.value(0).toInt();
    if(query.value(0).toInt()==0){
        cout<<"不存在"<<endl;
        return false;
    }
    qDebug()<<query.value(0).toInt();
    return true;
}

int DataBase::getRandom()
{
//    srand((int)time(nullptr));
    int result;
    result=(rand()%(99999-10000+1))+10000;
    return result;
}
