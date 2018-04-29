#pragma once

#include <iostream>
#include "DataBase.h"


using namespace std;
class Logement
{
private:
    MYSQL* conn;
	unsigned int id;
	unsigned int idProp;
	string title;
	string descrip;
	DataBase* DB = new DataBase();

public:

	//crud
	void addLogement(int id_owner);
    void editLogement(int id);
    void deleteLogement(int id);
    void showLogement(int id);
    void showAll();
    //constructor destructor
	Logement();
	~Logement();
};

