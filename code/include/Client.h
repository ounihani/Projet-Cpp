#ifndef _CLIENT_H
#define _CLIENT_H

#include "User.h"
#include <string>
#include "DataBase.h"
#include "Personne.h"

class Client : public Personne {
public:

	void acheter();

	void louer();

	void editProfile(int);

	void getLogementList();

	void reportProblem();

    void addPerson();
    void editPerson(int id);
    void deletePerson(int id);
    void showPerson(int id);
    void showAll();

private:
    string password;
    DataBase *DB = new DataBase();
};

#endif //_CLIENT_H
