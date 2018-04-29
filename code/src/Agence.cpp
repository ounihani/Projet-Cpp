

#include "Agence.h"
#include "Problem.h"
#include "employee.h"
#include "BuyingContrat.h"
#include "RentingContrat.h"
#include "Client.h"
#include "Logement.h"
#include "Proprietaire.h"


void Agence::getProblemsList() {
    Problem p;
    p.showAll();
}

void Agence::getReclamations() {

}

void Agence::getSuggestions() {

}

void Agence::DeleteSuggestion() {
    Problem p;
    cout<<"donner l'identifiant du probleme a supprimer"<<endl;
    int id_p;
    cin>>id_p;
    p.deleteProblem(id_p);
}

void Agence::addEmployee() {
    Employee e;
    e.addPerson();
}

void Agence::editEmployee() {
    Employee e;
    cout<<"donner l'identifiant de l'employee a modifier"<<endl;
    int id_e;
    cin>>id_e;
    e.editPerson(id_e);
}

void Agence::deleteEmployee() {
    Employee e;
    cout<<"donner l'identifiant de l'employee a supprimer"<<endl;
    int id_e;
    cin>>id_e;
    e.deletePerson(id_e);
}

void Agence::getEmployeesList() {
    Employee e;
    e.showAll();
}

void Agence::getContracts() {
    cout<<"you are about to see all the Buying contracts"<<endl;
    BuyingContrat bc;
    bc.showAll();
    cout<<"you are about to see all the renting contracts"<<endl;
    RentingContrat rc;
    rc.showAll();
}

void Agence::signContract() {
    cout<<"doneer le type du contrat "<<endl<<"1- achat"<<endl<<"2- location"<<endl;
    int type_contrat;
    cin>>type_contrat;

    if(type_contrat=1){
        BuyingContrat bc;
        cout<<"saisir l'identifiant du contrat a signer"<<endl;
        int id;
        cin>>id;
        bc.signContact(id);
    }else if(type_contrat=2){

        RentingContrat rc;
        cout<<"saisir l'identifiant du contrat a signer"<<endl;
        int id;
        cin>>id;
        rc.signContact(id);
    }else{
    cout<<"choix invalide"<<endl;
    }
}

void Agence::addCustomerAccount() {
    Client c;
    c.addPerson();
}

void Agence::deleteCustomer() {
    Client c;
    cout<<"donner l'identifiant du perssonne a supprimer"<<endl;
    int id;
    cin>>id;
    c.deletePerson(id);
}

void Agence::updateCustomer() {
    Client c;
    cout<<"donner l'identifiant du perssonne a modifier"<<endl;
    int id;
    cin>>id;
    c.editPerson(id);
}

void Agence::DeleteLogement() {
    Logement l;
    cout<<"donner l'identifiant du logement a modifier"<<endl;
    int id;
    l.deleteLogement(id);

}

void Agence::getLogements() {
    Logement l;
    l.showAll();
}

void Agence::getDepences() {
    DB->getQuery("SELECT sum(salaire) FROM `employee`");
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    cout<<"les depences mensuel de l'agence sont "<<row[0]<<endl;
}

void Agence::getBenefice() {

    DB->getQuery("SELECT sum(value) FROM `buying_contract`");
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    cout<<"Le benefice total de l'agence est : "<<row[0]<<endl;

    DB->getQuery("SELECT sum(amount_per_month) FROM `renting_contract`");
    DB->executeQuery();
    DB->getResult();
    row = DB->fetchRow();
    cout<<"Le benefice mensuel de l'agence est : "<<row[0]<<endl;
}

void Agence::getFrais() {

}

int Agence::getId()
{
	return id;
}



string Agence::getName()
{
	return name;
}

void Agence::getCustomersList()
{
    Client c;
    c.showAll();
}
void Agence::showClient()
{
    Client c;
    int id;
    cout<<"donner l'id de l'employée a afficher"<<endl;
    cin>>id;
    c.showPerson(id);
}
void Agence::editClient()
{
    Client e;
    cout<<"donner l'identifiant client a modifier"<<endl;
    int id_e;
    cin>>id_e;
    e.editPerson(id_e);
}

void Agence::getProprietaireList()
{
    Proprietaire p;
    p.showAll();
}

void Agence::getPropInfo()
{
    cout<<"donner l'identifiant prop a afficher"<<endl;
    int id;
    cin>>id;
    Proprietaire p;
    p.showPerson(id);

}

void Agence::editProp()
{
    cout<<"donner l'identifiant prop a modifier"<<endl;
    int id;
    cin>>id;
    Proprietaire p;
    p.showPerson(id);

}

void Agence::addProp()
{
    Proprietaire p;
    p.addPerson();
}

void Agence::deleteProp()
{
cout<<"donner l'identifiant prop a supp"<<endl;
    int id;
    cin>>id;
    Proprietaire p;
    p.deletePerson(id);
}


