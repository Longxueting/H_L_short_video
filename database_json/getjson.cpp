#include "getjson.h"
#include <vector>
#include "json/json.h"
#include <fstream>
#include <cstdlib>
#include <mysql/mysql.h>
GetJson::GetJson(){}

GetJson::GetJson(std::string tablemame)
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

GetJson::~GetJson(){}
