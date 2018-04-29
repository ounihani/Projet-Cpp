#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include "DataBase.h"
#include "Personne.h"

class Employee : public Personne {
public:
	Employee();
	Employee( string, string, string, string, float);

    void addPerson();
    void editPerson(int id);
    void deletePerson(int id);
    void showPerson(int id);
    void showAll();

    friend ostream &operator<<( ostream &output, const Employee &e);
private:
	string poste;
	float salaire;
	DataBase* DB = new DataBase();
};

#endif
