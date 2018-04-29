#include "Employee.h"
#include <string>
#include <sstream>


Employee::Employee():Personne() {

}
Employee::Employee( string name, string surname, string dateOfBirth, string poste, float salaire):Personne(name,surname, dateOfBirth)
{
	this->poste = poste;
	this->salaire = salaire;
}

void Employee::addPerson()
{
      cout<<"Input employee info"<<endl;
      cout<<"1- name"<<endl;
      cin>>this->name;
      cout<<"2- surname"<<endl;
      cin>>this->subname;
      cout<<"3- birthdate"<<endl;
      cin>>this->birthDate;
      cout<<"4- poste"<<endl;
      cin>>this->poste;
      cout<<"5- salary"<<endl;
      cin>>this->salaire;

      ostringstream str1;
      str1 << this->salaire;
      string sal= str1.str();

      DB->getQuery("INSERT INTO `employee` (`name`, `surname`, `date_of_birth`, `poste`, `salaire`) VALUES ( '"+this->name+"', '"+this->subname+"', '"+this->birthDate+"', '"+this->poste+"', '"+sal+"')");
      DB->executeQuery();


}

void Employee::editPerson(int id)
{
    int choice;
    string x;
    float y;
    bool f_changed=false;

    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from employee where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    this->id=atoi(row[0]);
    this->name=row[1];
    this->subname=row[2];
    this->birthDate=row[3];
    this->poste=row[4];

    do{
      cout<<"select what you want to edit"<<endl;
      cout<<"1- name"<<endl;
      cout<<"2- surname"<<endl;
      cout<<"3- birthdate"<<endl;
      cout<<"4- poste"<<endl;
      cout<<"5- salary"<<endl;
      cout<<"6- save"<<endl;
      cin>>choice;



      switch(choice){
        case 1 : cin >>x; this->name=x;break;
        case 2 : cin >>x; this->subname=x;break;
        case 3 : cin >>x; this->birthDate=x;break;
        case 4 : cin >>x; this->poste=x;break;
        case 5 : cin >>y; this->salaire=y;f_changed=true;break;
      }

    }
    while(choice != 6);

    if(f_changed){
    ostringstream str2;
    str2 << this->salaire;
    string sal= str2.str();

    DB->getQuery("UPDATE `employee` SET `name` = '"+this->name+"', `surname` = '"+this->subname+"', `date_of_birth` = '"+this->birthDate+"', `poste` = '"+this->poste+"', `salaire` = '"+sal+"' WHERE `employee`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
    }else{

    DB->getQuery("UPDATE `employee` SET `name` = '"+this->name+"', `surname` = '"+this->subname+"', `date_of_birth` = '"+this->birthDate+"', `poste` = '"+this->poste+"' WHERE `employee`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();

    }



}

void Employee::deletePerson(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("DELETE FROM `employee` WHERE `employee`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
}

void Employee::showPerson(int id)
{

    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from employee where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();

    cout<<"---------------------------------"<<endl;
    cout<<"Name: "<<row[1]<<endl;
    cout<<"Surname: "<<row[2]<<endl;
    cout<<"Birthdate : "<<row[3]<<endl;
    cout<<"Job: "<<row[4]<<endl;
    cout<<"salaire: "<<atof (row[5])<<endl;
    cout<<endl;

}

void Employee::showAll()
{
    DB->getQuery("select * from employee");
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    while(row = DB->fetchRow()){
    cout<<"---------------------------------"<<endl;
    cout<<"Name: "<<row[1]<<endl;
    cout<<"Surname: "<<row[2]<<endl;
    cout<<"Birthdate : "<<row[3]<<endl;
    cout<<"Job: "<<row[4]<<endl;
    cout<<"salaire: "<<atof (row[5])<<endl;
    cout<<endl;
    }

    while(row = DB->fetchRow()){
    cout<<"---------------------------------"<<endl;
    cout<<"Name: "<<row[1]<<endl;
    cout<<"Surname: "<<row[2]<<endl;
    cout<<"Birthdate : "<<row[3]<<endl;
    cout<<"Job: "<<row[4]<<endl;
    cout<<"salaire: "<<atof (row[5])<<endl;
    cout<<endl;
    }
}

    ostream &operator<<( ostream &output, const Employee &e) {
    cout<<"---------------------------------"<<endl;
    cout<<"Name: "<< e.name <<endl;
    cout<<"Surname: "<<e.subname<<endl;
    cout<<"Birthdate : "<<e.birthDate<<endl;
    cout<<"Job: "<<e.poste<<endl;
    cout<<"salaire: "<<e.salaire<<endl;
    cout<<endl;

    return output;
}


