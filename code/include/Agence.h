/**
* Project Untitled
*/


#ifndef _AGENCE_H
#define _AGENCE_H

#include <iostream>
#include "DataBase.h"

using namespace std;
class Agence {

private:
	unsigned int id;
	string name;
	string password;
    DataBase *DB = new DataBase;


public:

	void getProblemsList();

	void getReclamations();

	void getSuggestions();

	void DeleteSuggestion();

	void addEmployee();

	void editEmployee();

	void deleteEmployee();

	void getEmployeesList();

	void getContracts();

	void signContract();

	void addCustomerAccount();
    void getCustomersList();
	void deleteCustomer();

	void updateCustomer();
    void showClient();
    void editClient();

    void getProprietaireList();
    void getPropInfo();
    void editProp();
    void addProp();
    void deleteProp();




	void DeleteLogement();

	void getLogements();

	void getDepences();

	void getBenefice();

	void getFrais();

	int getId();

	string getName();

    string getPassword(){
        return password;
    }

    Agence(){
        id=1;
        name="El AMEN AGENCY";
        password="amen";
	}

};

#endif //_AGENCE_H
