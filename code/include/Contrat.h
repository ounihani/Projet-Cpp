/**
* Project Untitled
*/

#ifndef _CONTRATS_H
#define _CONTRATS_H
#include <iostream>

using namespace std;
class Contrat {
public:
    Contrat();
    ~Contrat();

    //crud
    virtual void addContrat();
    virtual void editContrat(int id);
    virtual void deleteContrat(int id);
    virtual void showContrat(int id);
    virtual void showAll();

    // Contracts operations
    virtual void showClosedContracts();
    virtual void showPendingContracts();
    virtual void signContact();
protected:

    int state;
    int id;
	int idLogement;
	int  idClient;
private:



};

#endif //_CONTRATS_H
