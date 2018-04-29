#include "BuyingContrat.h"
#include <sstream>
#include "Logement.h"
BuyingContrat::BuyingContrat()
{

}

BuyingContrat::~BuyingContrat()
{

}

void BuyingContrat::addContrat(int id_logement,int id_client)
{
  cout<<"Input renting contract info:"<<endl;
      cout<<"3- Contract value"<<endl;
      cin>>this->value;

      this->state=0;
      this->idClient=id_client;
      this->idLogement=id_logement;

      ostringstream str1;
      str1 << this->value;
      string amount= str1.str();

      ostringstream str2;
      str2 << this->idClient;
      string idc= str2.str();

      ostringstream str3;
      str3 << this->idLogement;
      string idl= str3.str();

      ostringstream str4;
      str4 << this->state;
      string state= str4.str();

      DB->getQuery("INSERT INTO `buying_contract` ( `id_logement`, `id_client`, `status`,  `value`) VALUES ( '"+idc+"', '"+idl+"', '"+state+"', '"+amount+"');");
      DB->executeQuery();
}

void BuyingContrat::editContrat(int id)
{

    int choice;
    int x;
    float y;

    bool f_changed=false;

    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from buying_contract where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    this->id=atoi(row[0]);
    this->idLogement=atoi(row[1]);
    this->idClient=atoi(row[2]);
    this->state=atoi(row[3]);
    this->value=atof(row[4]);

    do{
      cout<<"select what you want to edit"<<endl;
      cout<<"1- value "<<endl;
      cout<<"2- id logement"<<endl;
      cout<<"3- save"<<endl;
      cin>>choice;



      switch(choice){
        case 1 : cin >>y; this->value=y;break;
        case 2 : cin >>x; this->idLogement=x;break;

      }

    }
    while(choice != 3);

      ostringstream str3;
      str3 << this->idLogement;
      string idl= str3.str();

    if(f_changed){
    ostringstream str2;
    str2 << this->value;
    string val= str2.str();



    DB->getQuery("UPDATE `buying_contract` SET `id_logement` = '"+idl+"', `value` = '"+val+"' WHERE `buying_contract`.`id` = "+p_id);
   DB->executeQuery();
    DB->getResult();
    }else{

    DB->getQuery("UPDATE `buying_contract` SET `id_logement` = '"+idl+"' WHERE `buying_contract`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();

    }

}

void BuyingContrat::deleteContrat(int id)
{
ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("DELETE FROM `buying_contract` WHERE `buying_contract`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
}

void BuyingContrat::showContrat(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from buying_contract where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();

    cout<<"---------------------------------"<<endl;
    Logement l;
    l.showLogement(atoi(row[0]));
    cout<<"status: "<<row[3]<<endl;
    cout<<"Value: "<<row[4]<<endl;
    cout<<endl;
}

void BuyingContrat::showAll()
{
     ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from buying_contract where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
     while(row = DB->fetchRow()){
    cout<<"---------------------------------"<<endl;
    Logement l;
    l.showLogement(atoi(row[0]));
    cout<<"status: "<<row[3]<<endl;
    cout<<"Value: "<<row[4]<<endl;
    cout<<endl;
     }
}

void BuyingContrat::showClosedContracts()
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from buying_contract where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    while(row = DB->fetchRow()){
    if(row[3]){
        cout<<"---------------------------------"<<endl;
        Logement l;
        l.showLogement(atoi(row[0]));
        cout<<"status: "<<row[3]<<endl;
        cout<<"Value: "<<row[4]<<endl;
        cout<<endl;
         }
    }
}

void BuyingContrat::showPendingContracts()
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from buying_contract where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    while(row = DB->fetchRow()){
    if(!row[3]){
        cout<<"---------------------------------"<<endl;
        Logement l;
        l.showLogement(atoi(row[0]));
        cout<<"status: "<<row[3]<<endl;
        cout<<"Value: "<<row[4]<<endl;
        cout<<endl;
         }
    }
}

void BuyingContrat::signContact(int)
{
 ostringstream str1;
    str1 << id;
    string p_id = str1.str();



    DB->getQuery("UPDATE `buying_contract` SET `status` = '1'WHERE `buying_contract`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
}
