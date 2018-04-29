#include "Client.h"
#include <sstream>
#include "Logement.h"
#include "Problem.h"
#include <string>
#include "BuyingContrat.h"
#include "RentingContrat.h"


using namespace std;

void Client::acheter() {

    int id_logement;
    cout<<"donner l'identifiant du bien a acheter"<<endl;
    cin>>id_logement;

    BuyingContrat c;
    c.addContrat(id_logement,this->id);
}

void Client::louer() {
    int id_logement;
    cout<<"donner l'identifiant du bien a louer"<<endl;
    cin>>id_logement;

    RentingContrat c;
    c.addContrat(id_logement,this->id);
}

void Client::editProfile(int id) {

    int choice;
    string x;
    bool f_changed=false;

    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from client where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    this->id=atoi(row[0]);
    this->name=row[1];
    this->subname=row[2];
    this->birthDate=row[3];
    this->password=row[4];

    do{
      cout<<"select what you want to edit"<<endl;
      cout<<"1- name"<<endl;
      cout<<"2- surname"<<endl;
      cout<<"3- birthdate"<<endl;
      cout<<"4- password"<<endl;
      cout<<"5- save"<<endl;
      cin>>choice;

      switch(choice){
        case 1 : cin >>x; this->name=x;break;
        case 2 : cin >>x; this->subname=x;break;
        case 3 : cin >>x; this->birthDate=x;break;
        case 4 : cin >>x; this->password=x;break;
      }

    }
    while(choice != 5);



    DB->getQuery("UPDATE `client` SET `name` = '"+this->name+"', `surname` = '"+this->subname+"', `date_of_birth` = '"+this->birthDate+"', `password` = '"+this->password+"' WHERE `client`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();

}

void Client::getLogementList() {
    Logement l;
    l.showAll();
}

void Client::reportProblem() {
    int id_logement;
    string title;
    string description;
    cout<<"------------------------------------"<<endl;
    cout<<"input the problem information"<<endl;
    cout<<"donner l'identifiant du logement a signaler"<<endl;
    cin>>id_logement;

    cout<<"donner le titre du probleme"<<endl;
    cin.ignore();
    cin>>title;
    cin.ignore();
    cout<<"donner la description probleme"<<endl;
    std::getline (std::cin,description);
    cin.ignore();
    Problem p;
    p.createProblem(this->id,id_logement, title, description);

}


void Client::addPerson()
{
 cout<<"Input Client info"<<endl;
      cout<<"1- name"<<endl;
      cin>>this->name;
      cout<<"2- surname"<<endl;
      cin>>this->subname;
      cout<<"3- birthdate"<<endl;
      cin>>this->birthDate;
      cout<<"4- password"<<endl;
      cin>>this->password;




      DB->getQuery("INSERT INTO `client` (`id`, `name`, `surname`, `date_of_birth`, `password`) VALUES (NULL, '"+this->name+"', '"+this->subname+"', '"+this->birthDate+"', '"+this->password+"');");
      DB->executeQuery();

}

void Client::editPerson(int id)
{
int choice;
    string x;

    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from client where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    this->id=atoi(row[0]);
    this->name=row[1];
    this->subname=row[2];
    this->birthDate=row[3];
    this->password=row[4];

    do{
      cout<<"select what you want to edit"<<endl;
      cout<<"1- name"<<endl;
      cout<<"2- surname"<<endl;
      cout<<"3- birthdate"<<endl;
      cout<<"4- password"<<endl;
      cout<<"5- save"<<endl;
      cin>>choice;



      switch(choice){
        case 1 : cin >>x; this->name=x;break;
        case 2 : cin >>x; this->subname=x;break;
        case 3 : cin >>x; this->birthDate=x;break;
        case 4 : cin >>x; this->password=x;break;
      }

    }
    while(choice != 5);

    DB->getQuery("UPDATE `client` SET `name` = '"+this->name+"', `surname` = '"+this->subname+"', `password` = '"+this->password+"', `date_of_birth` = '"+this->birthDate+"' WHERE `proprietaire`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();

}

void Client::deletePerson(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("DELETE FROM `client` WHERE `proprietaire`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
}

void Client::showPerson(int id)
{
ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from client where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();

    cout<<"---------------------------------"<<endl;
    cout<<"Name: "<<row[1]<<endl;
    cout<<"Surname: "<<row[2]<<endl;
    cout<<"Birthdate : "<<row[3]<<endl;
    cout<<endl;
}

void Client::showAll()
{
    DB->getQuery("select * from client");
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;

    while(row = DB->fetchRow()){
    cout<<"---------------------------------"<<endl;
    cout<<"Name: "<<row[1]<<endl;
    cout<<"Surname: "<<row[2]<<endl;
    cout<<"Birthdate : "<<row[3]<<endl;
    cout<<endl;
    }
}



