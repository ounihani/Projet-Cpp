#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <windows.h>
#include <mysql.h>

using namespace std;
class DataBase
{
   private:
        MYSQL* conn;
        MYSQL_RES *res;
        string query;

    public:
        DataBase();
        ~DataBase();
        void getQuery(string query);
        void executeQuery();
        void getResult();
        MYSQL_ROW fetchRow();

    protected:


};

#endif // DATABASE_H
