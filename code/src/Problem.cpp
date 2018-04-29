#include "Problem.h"
#include <windows.h>
#include <mysql.h>
#include <string>
#include <sstream>
#include "Client.h"

Problem::Problem()
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","pfa_cpp",0,NULL,0);
     if(!conn){
        exit(-1);
     }
}


Problem::~Problem()
{
}

int Problem::getId()
{
	return id;
}

void Problem::setId(int id)
{
	this->id = id;
}

string Problem::getTitle()
{
	return title;
}

void Problem::setTitle(string title)
{
	this->title = title;
}

string Problem::getDescription()
{
	return descrip;
}

void Problem::setDescription(string descrip)
{
	this->descrip = descrip;
}

int Problem::getIdReporter()
{
	return idReporter;
}

void Problem::setIdReporter(int idReporter)
{
	this->idReporter = idReporter;
}

int Problem::getIdLogement()
{
	return idLogement;
}

void Problem::setIdLogement(int idLogement)
{
	this->idLogement = idLogement;
}

//CRUD
void Problem::createProblem(int id_reporter,int id_logement, string title, string description )
{

        ostringstream str1;
        str1<<id_reporter;
        string p_id = str1.str();

        ostringstream str2;
        str2<<id_logement;
        string l_id = str2.str();

    // the str() coverts number into string
    string id = str1.str();

        string query =("INSERT INTO `problem` (`id_reporter`, `id_logement`, `title`, `description`) VALUES ('"+l_id+"', '"+p_id+"', '"+title+"', '"+description+"');");

        int qstate = mysql_query(conn,query.c_str());

        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
}

void Problem::getProblem(int id_problem)
{
    int p_id = id_problem;
    ostringstream str1;
    str1 << p_id;
    string id = str1.str();

    int queryState = mysql_query(conn,("SELECT * FROM `problem` where id="+id).c_str());
    if(!queryState){
         MYSQL_RES *res = mysql_store_result(conn);
         MYSQL_ROW row;
         row=mysql_fetch_row(res);
         this->id=atoi (row[0]);
         this->idReporter=atoi (row[1]);
         this->idLogement=atoi (row[2]);
         this->title= row[3];
         this->descrip= row[4];

    }
    else{
        cout<<"Problem with the query"<<endl;
    }
}

void Problem::editProblem(int id_problem)
{
        ostringstream str1;
        str1<<this->idReporter;
        string p_id = str1.str();

        ostringstream str2;
        str2<<this->idLogement;
        string l_id = str2.str();

        ostringstream str3;
        str3<<id_problem;
        string id = str3.str();

        string query =("UPDATE `problem` SET `id_reporter` = '"+p_id+"', `id_logement` = '"+l_id+"', `title` = '"+this->title+"', `description` = '"+this->descrip+"' WHERE `problem`.`id` = "+id+";");

        int qstate = mysql_query(conn,query.c_str());

        if(!qstate)
            cout<<"record updated successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
}

void Problem::deleteProblem(int idProblem)
{
        ostringstream str1;
        str1<<idProblem;
        string id = str1.str();
        string query="DELETE FROM `problem` WHERE `problem`.`id` = "+id;
        int qstate = mysql_query(conn,query.c_str());
        if(!qstate)
            cout<<"record deleted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
}


void Problem::showAll()
{
    DB->getQuery("select * from problem");
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    Client c;
    while(row = DB->fetchRow()){
    cout<<"---------------------------------"<<endl;
    cout<<"info sur la personne qui a reporte ce probleme"<<endl;
    c.showPerson(atoi(row[1]));
    cout<<"Title: "<<row[3]<<endl;
    cout<<"Descriptoion: "<<row[4]<<endl;

    cout<<endl;
    }
}
