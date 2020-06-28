#include "getjson.h"
#include <vector>
#include "json/json.h"
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdio.h>
#include <mysql/mysql.h>

using namespace std;
GetJson::GetJson(){}

void GetJson::GetTableJson(std::string tablemame)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(
                &mysql,
                "localhost",
                "root",
                "",
                "short_video",
                3306,
                NULL,
                0
                );
    string sql;
    MYSQL_RES *result=NULL;
    result=mysql_store_result(&mysql);
    sql = "select * from " + tablemame;
    mysql_query( &mysql, sql.c_str() ); //查询当前命令

    cout << sql << endl;
    //得到表中列的数量
    result = mysql_store_result( &mysql );

    MYSQL_FIELD* field = NULL;

    ofstream os;
    string tableName = tablemame + ".json";
    os.open( tableName.c_str() );

    Json::Value jsonTable;
    MYSQL_ROW row1 = mysql_fetch_row( result );
    int field_count = mysql_num_fields( result );
    while ( NULL != row1 )
    {
        Json::Value jsonRow;
        for(int i = 0; i < field_count; ++i)
        {
            field = mysql_fetch_field_direct( result, i );

            switch(field->type)
            {
            case MYSQL_TYPE_TINY:
                cout << "MYSQL_TYPE_TINY" << endl;
                break;
            case MYSQL_TYPE_SHORT:
                cout << "MYSQL_TYPE_SHORT" << endl;
                break;
            case MYSQL_TYPE_BLOB:
                cout << "MYSQL_TYPE_BLOB" << endl;
                break;
            case MYSQL_TYPE_LONG:
                jsonRow[field->name] = Json::Value( atoi(row1[i]) );
                cout << "MYSQL_TYPE_LONG" << endl;
                break;
            case MYSQL_TYPE_VAR_STRING:
                cout << "MYSQL_TYPE_VAR_STRING" << endl;
                jsonRow[field->name] = Json::Value( row1[i] );
                break;
            }

        }

        row1 = mysql_fetch_row( result );
        //cout << *cit << endl;

        jsonTable.append(jsonRow);
    }


    os << jsonTable;
//    os << flush;
    os.close();
}

void GetJson::GetOriginalVideo(string author)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(
                &mysql,
                "localhost",
                "root",
                "",
                "short_video",
                3306,
                NULL,
                0
                );
    string sql;
    MYSQL_RES *result=NULL;
    result=mysql_store_result(&mysql);
    sql = "select * from VideoTable where v_author='"+author+"';" ;
    mysql_query( &mysql, sql.c_str() ); //查询当前命令

    cout << sql << endl;
    //得到表中列的数量
    result = mysql_store_result( &mysql );

    MYSQL_FIELD* field = NULL;

    ofstream os;
    string tableName ="OriginVideo.json";
    os.open( tableName.c_str() );

    Json::Value jsonTable;
    MYSQL_ROW row1 = mysql_fetch_row( result );
    int field_count = mysql_num_fields( result );
    while ( NULL != row1 )
    {
        Json::Value jsonRow;
        for(int i = 0; i < field_count; ++i)
        {
            field = mysql_fetch_field_direct( result, i );

            switch(field->type)
            {
            case MYSQL_TYPE_TINY:
                cout << "MYSQL_TYPE_TINY" << endl;
                break;
            case MYSQL_TYPE_SHORT:
                cout << "MYSQL_TYPE_SHORT" << endl;
                break;
            case MYSQL_TYPE_BLOB:
                cout << "MYSQL_TYPE_BLOB" << endl;
                break;
            case MYSQL_TYPE_LONG:
                jsonRow[field->name] = Json::Value( atoi(row1[i]) );
                cout << "MYSQL_TYPE_LONG" << endl;
                break;
            case MYSQL_TYPE_VAR_STRING:
                cout << "MYSQL_TYPE_VAR_STRING" << endl;
                jsonRow[field->name] = Json::Value( row1[i] );
                break;
            }

        }

        row1 = mysql_fetch_row( result );
        //cout << *cit << endl;

        jsonTable.append(jsonRow);
    }


    os << jsonTable;
//    os << flush;
    os.close();
}
void GetJson::getTagJson(string tags){
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(
                &mysql,
                "localhost",
                "root",
                "",
                "short_video",
                3306,
                NULL,
                0
                );
    string sql;
    MYSQL_RES *result=NULL;
    result=mysql_store_result(&mysql);
    char tag[]={0};
    strncpy(tag,tags.c_str(),tags.length()+1);
    int tag_num=tags.length();
    switch (tag_num) {
    case 0:
        sql="select * from VideoTable";
        break;
    case 1:
        //string str_tag(1,tag[0]);
        sql="select * from VideoTable where v_tag like '%"+string(1,tag[0])+"%';";
        break;
    case 2:
        sql="select * from VideoTable where v_tag like '%"+string(1,tag[0])+"%' or v_tag like '%"+string(1,tag[0])+"%';";
        break;
    case 3:
        sql="select * from VideoTable where v_tag like '%"+string(1,tag[0])+"%' or v_tag like '%"+string(1,tag[0])+"%' or v_tag like '%"+string(1,tag[0])+"%';";
        break;
    default:
        sql="select * from VideoTable where v_tag like '%"+string(1,tag[0])+"%' or v_tag like '%"+string(1,tag[0])+"%' or v_tag like '%"+string(1,tag[0])+"%';";
        break;
    }
    mysql_query( &mysql, sql.c_str() ); //查询当前命令

    cout << sql << endl;
    //得到表中列的数量
    result = mysql_store_result( &mysql );

    MYSQL_FIELD* field = NULL;

    ofstream os;
    string tableName ="RecommendVideo.json";
    os.open( tableName.c_str() );

    Json::Value jsonTable;
    MYSQL_ROW row1 = mysql_fetch_row( result );
    int field_count = mysql_num_fields( result );
    while ( NULL != row1 )
    {
        Json::Value jsonRow;
        for(int i = 0; i < field_count; ++i)
        {
            field = mysql_fetch_field_direct( result, i );

            switch(field->type)
            {
            case MYSQL_TYPE_TINY:
                cout << "MYSQL_TYPE_TINY" << endl;
                break;
            case MYSQL_TYPE_SHORT:
                cout << "MYSQL_TYPE_SHORT" << endl;
                break;
            case MYSQL_TYPE_BLOB:
                cout << "MYSQL_TYPE_BLOB" << endl;
                break;
            case MYSQL_TYPE_LONG:
                jsonRow[field->name] = Json::Value( atoi(row1[i]) );
                cout << "MYSQL_TYPE_LONG" << endl;
                break;
            case MYSQL_TYPE_VAR_STRING:
                cout << "MYSQL_TYPE_VAR_STRING" << endl;
                jsonRow[field->name] = Json::Value( row1[i] );
                break;
            }

        }

        row1 = mysql_fetch_row( result );
        //cout << *cit << endl;

        jsonTable.append(jsonRow);
    }


    os << jsonTable;
//    os << flush;
    os.close();
}
GetJson::~GetJson(){}
