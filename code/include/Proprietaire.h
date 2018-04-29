#ifndef _PROPRIETAIRE_H
#define _PROPRIETAIRE_H

#include "DataBase.h"
#include "Personne.h"

class Proprietaire : public Personne {
    string password;
    DataBase *DB= new DataBase();

public:
    Proprietaire();
    Proprietaire(string, string, string);
    ~Proprietaire();
    void addPerson();
    void editPerson(int id);
    void deletePerson(int id);
    void showPerson(int id);
    void showAll();
	void addLogement();

	void editLogement(int id);

	void deleteLogement(int id);

	void getMyLogements();

	void getMyContracts();
};

#endif //_PROPRIETAIRE_H
