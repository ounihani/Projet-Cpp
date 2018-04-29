/**
* Project Untitled
*/


#ifndef _PROBLEM_H
#define _PROBLEM_H
#include <iostream>
#include <windows.h>
#include <mysql.h>
#include "DataBase.h"

using namespace std;
class Problem {
public:
    Problem();
    ~Problem();
	int getId();
	void setId(int);

	string getTitle();
	void setTitle(string);

	string getDescription();
	void setDescription(string);

	int getIdReporter();
	void setIdReporter(int);

	int getIdLogement();
	void setIdLogement(int);

    void createProblem(int id_reporter,int id_logement, string title, string description);
    void getProblem(int id_problem);
    void editProblem(int id_problem);
    void deleteProblem(int idProblem);
    void showAll();



private:
	unsigned int id;
	int idReporter;
	int idLogement;
	string title;
	string descrip;
    DataBase *DB = new DataBase;
   	MYSQL* conn;
};

#endif //_PROBLEM_H
