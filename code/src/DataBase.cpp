#include "DataBase.h"

DataBase::DataBase()
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","pfa_cpp",0,NULL,0);
     if(!conn){
        exit(-1);
     }
}

DataBase::~DataBase()
{
    //delete conn;
}

void DataBase::getQuery(string query)
{
    this->query=query;
}

void DataBase::executeQuery()
{
    int queryState =  mysql_query(conn,query.c_str());
    if(queryState){
        exit(-1);
    }
}

void DataBase::getResult()
{
    res = mysql_store_result(conn);
}

MYSQL_ROW DataBase::fetchRow()
{
    return mysql_fetch_row(res);
}
