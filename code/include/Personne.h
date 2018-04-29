#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>
#include <string.h>
#include "date.h"
using namespace std;

class Personne
{
	//surcharge d'operateur << (affichage)
	//constructeur avec les parametres
public:

    unsigned int id;
	Personne();
	~Personne();
	Personne(string, string, string);
	string Getname() { return name; }
	void Setname(string val) { name = val; }
	string Getsubname() { return subname; }
	void Setsubname(string val) { subname = val; }
	string GetbirthDate() { return birthDate; }
	void SetbirthDate(string val) { birthDate = val; }
    virtual void addPerson()=0;
    virtual void editPerson(int id)=0;
    virtual void deletePerson(int id)=0;
    virtual void showPerson(int id)=0;
    virtual void showAll()=0;



protected:
	string name;
	string subname;
	string birthDate;
private:

};

#endif // PERSONNE_H
