#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <string>
#include <vector>
#include "json/json.h"
#include <fstream>
#include <cstdlib>
#include <mysql/mysql.h>

using namespace std;
int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    return app.exec();
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
    string sql="show tables";
    mysql_query(&mysql,sql.c_str());

    MYSQL_RES *result=NULL;
    result=mysql_store_result(&mysql);
    vector<string> tables;
    MYSQL_ROW row = NULL;

    //得到所有的表
    row = mysql_fetch_row( result );
    while ( NULL != row )
    {
        tables.push_back( row[0] );
        cout << row[0] << endl;
        row = mysql_fetch_row( result );
    }
    for(vector<string>::const_iterator cit = tables.begin(); cit != tables.end(); ++ cit)
    {
        sql = "select * from " + *cit;
        mysql_query( &mysql, sql.c_str() );

        cout << sql << endl;
        //得到表中列的数量
        result = mysql_store_result( &mysql );

        MYSQL_FIELD* field = NULL;

        ofstream os;
        string tableName = *cit + ".json";
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
        os << flush;
        os.close();
    }

    return 0;
}
