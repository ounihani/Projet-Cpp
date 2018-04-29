#include <iostream>
#include <windows.h>
#include <mysql.h>
#include "User.h"
#include "Logement.h"
#include "Problem.h"
#include "Agence.h"
#include "employee.h"
#include "Logement.h"
#include "Proprietaire.h"
#include "RentingContrat.h"
#include "BuyingContrat.h"
#include "Client.h"
#include "Agence.h"

using namespace std;



int main()
{
  int choix;
  int choix2;
  int id;
  string password;
do{
  cout<<"type of user ?"<<endl;
  cout<<"1- Agency"<<endl;
  cout<<"2- client"<<endl;
  cout<<"3- proprietaire"<<endl;
  cin>>choix;
}while((choix>3)||choix<1);

if(choix==1){

    cout<<endl;
    do{
      cout<<"choose an option"<<endl;
      cout<<"------------Analytics---------------------"<<endl;
      cout<<"1- show Benefice"<<endl;
      cout<<"2- show depences"<<endl;
        cout<<endl;
      cout<<"------------Employees management----------"<<endl;
      cout<<"3- add employee"<<endl;
      cout<<"4- edit employee information"<<endl;
      cout<<"5- get employee information"<<endl;
      cout<<"6- delete employee "<<endl;
      cout<<"7- get all employees"<<endl;
        cout<<endl;
      cout<<"------ Problems management--------"<<endl;
      cout<<"8- problems list"<<endl;
      cout<<"9- delete problem"<<endl;
        cout<<endl;
      cout<<"-------------Real estate Management--------------"<<endl;
      cout<<"10- Get real estates  List"<<endl;
      cout<<"11- Get real estate"<<endl;
      cout<<"12- Delete real estate"<<endl;
        cout<<endl;
      cout<<"-------------Clients Management--------------"<<endl;
      cout<<"13- Get Clinet List"<<endl;
      cout<<"14- show client"<<endl;
      cout<<"15- edit client"<<endl;
      cout<<"16- delete client"<<endl;
      cout<<"17- create client account"<<endl;
        cout<<endl;
      cout<<"-------------proprietare Management--------------"<<endl;
      cout<<"18- Get proprietaires List"<<endl;
      cout<<"19- Get Get proprietaires"<<endl;
      cout<<"20- Delete Get proprietaires"<<endl;
        cout<<endl;
      cout<<"-------------Sign a contract--------------"<<endl;
      cout<<"21- Sign a contract"<<endl;
      cout<<"22- exit"<<endl;
        //crud client/ proprietaire
      cin>>choix2;
      Agence a;
      Problem p;
      Employee e;
      Logement l;
      Client c;
      int id;
      switch(choix2){
        case 1 : a.getBenefice();break;
        case 2 : a.getDepences();break;
        case 3 : a.addEmployee();break;
        case 4 : a.editEmployee();break;
        case 5 : cout<<"donner l'id de l'employe a afficher"<<endl;cin>>id;e.showPerson(id);break;
        case 6 : a.editEmployee();break;
        case 7 : a.getEmployeesList();break;
        case 8 : a.getProblemsList();break;
        case 9 : cout<<"donner l'id du problème a supprimmer"<<endl;cin>>id;p.deleteProblem(id);break;
        case 10: a.getLogements();break;
        case 11: cout<<"donner l'id du Logement a afficher"<<endl;cin>>id;l.showLogement(id);break;
        case 12: a.DeleteLogement();break;
        case 13: a.getCustomersList();break;
        case 14: a.showClient();break;
        case 15: a.editClient();break;
        case 16: a.deleteCustomer();break;
        case 17: a.addCustomerAccount();break;
        case 18: a.getProprietaireList();break;
        case 19: a.getPropInfo();break;
        case 20: a.deleteProp();break;
        case 21: a.signContract();break;
      }

    }while(choix2!=22);

}else if(choix==2){
    Client c;
    cout<<"you are logged in as an client"<<endl;
    do{
      cout<<"choose an option"<<endl;
      cout<<"------------Profile Management---------------------"<<endl;
      cout<<"1- check information"<<endl;
      cout<<"2- edit information"<<endl;
        cout<<endl;
      cout<<"------Real estate buying--------"<<endl;
      cout<<"3- Get real estates list"<<endl;
      cout<<"4- Report a problem"<<endl;
      cout<<"5- Buy a real estate"<<endl;
      cout<<"6- rent a real estate"<<endl;
      cout<<"7- exit"<<endl;
        cout<<endl;

      cin>>choix2;

    switch(choix2){
        case 1 : cout<<"Type the id of the customer to show"<<endl;cin>>id;c.showPerson(id);break;
        case 2 : cout<<"Type the id of customer to edit"<<endl;cin>>id;c.editPerson(id);break;
        case 3 : c.getLogementList();break;
        case 4 : cout<<"Type the id of the real estate to report"<<endl;cin>>id;c.reportProblem();break;
        case 5 : cout<<"Type the id of the real estate to buy"<<endl;cin>>id;c.acheter();break;
        case 6 : cout<<"Type the id of the real estate to buy"<<endl;cin>>id;c.louer();break;
    }


    }while((choix>12)||choix<1);

}else if(choix==3){

    Proprietaire p;

    do{



     cout<<"you are logged in as an propietaire"<<endl;
     cout<<"choose an option"<<endl;
      cout<<"------------Profile Management---------------------"<<endl;
      cout<<"1- check information"<<endl;
      cout<<"2- edit information"<<endl;
        cout<<endl;
      cout<<"------Real estate Management--------"<<endl;
      cout<<"3- Get real estates list"<<endl;
//      cout<<"4- Get a real estate information "<<endl;
      cout<<"4- Edit real estate"<<endl;
      cout<<"5- Delete a real estate"<<endl;
      cout<<"6- Add a real estate"<<endl;
        cout<<endl;
      cout<<"------Real estate Management--------"<<endl;
      cout<<"-------------------------"<<endl;
      cout<<"7- exit"<<endl;

       switch(choix2){
        case 1 : p.showPerson(p.id);break;
        case 2 : p.editPerson(p.id);break;
        case 3 : p.getMyLogements();break;
        case 4 : cout<<"Type the id of the real estate to edit"<<endl;cin>>id;p.editLogement(id);break;
        case 5 : cout<<"Type the id of the real estate to delete"<<endl;cin>>id;p.deleteLogement(id);break;
        case 6 : p.addLogement();break;


       }
       cin>>choix2;

      }while(choix2!=7);



}

}
