#include "Proprietaire.h"
#include "Logement.h"
#include <sstream>

Proprietaire::Proprietaire()
{
this->id=1;
}

Proprietaire::Proprietaire(string name, string surname, string dateOfBirth)
{

}

Proprietaire::~Proprietaire()
{

}

void Proprietaire::addPerson()
{
      cout<<"Input employee info"<<endl;
      cout<<"1- name"<<endl;
      cin>>this->name;
      cout<<"2- surname"<<endl;
      cin>>this->subname;
      cout<<"3- birthdate"<<endl;
      cin>>this->birthDate;
      cout<<"4- password"<<endl;
      cin>>this->password;




      DB->getQuery("INSERT INTO `proprietaire` ( `name`, `surname`, `date_of_birth` , `password`) VALUES ( '"+this->name+"', '"+this->subname+"', '"+this->birthDate+"',  '"+this->password+"')");
      DB->executeQuery();
}

void Proprietaire::editPerson(int id)
{
 int choice;
    string x;
    bool f_changed=false;

    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from proprietaire where id = "+p_id);
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

    DB->getQuery("UPDATE `proprietaire` SET `name` = '"+this->name+"', `surname` = '"+this->subname+"', `password` = '"+this->password+"', `date_of_birth` = '"+this->birthDate+"' WHERE `proprietaire`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();

}

void Proprietaire::deletePerson(int id)
{
 ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("DELETE FROM `proprietaire` WHERE `proprietaire`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
}

void Proprietaire::showPerson(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from proprietaire where id = "+p_id);
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

void Proprietaire::showAll()
{
    DB->getQuery("select * from proprietaire");
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

void Proprietaire::addLogement()
{
    Logement l;
    l.addLogement(this->id);
}

void Proprietaire::editLogement(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    Logement l;
    DB->getQuery("select * from logement where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    if(this->id==(int) row[1]){
        l.editLogement(id);
    }else {
        cout<<"this real estate is not yours"<<endl;
    }
}

void Proprietaire::deleteLogement(int id)
{
     Logement l;

    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from logement where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    if(this->id == (int) row[1]){
        l.deleteLogement(id);
    }else {
        cout<<"this real estate is not yours"<<endl;
    }
}

void Proprietaire::getMyLogements()
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from logement where 'id_prop' = "+ p_id );
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;

    while(row = DB->fetchRow()){
    cout<<"---------------------------------"<<endl;
    cout<<"title: "<<row[2]<<endl;
    cout<<"Description: "<<row[3]<<endl;
    cout<<endl;
    }


}

void Proprietaire::getMyContracts()
{

}
