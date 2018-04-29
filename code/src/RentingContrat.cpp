#include "RentingContrat.h"

#include <sstream>
#include "Logement.h"
RentingContrat::RentingContrat()
{

}

RentingContrat::~RentingContrat()
{

}



void RentingContrat::addContrat(int id_logement,int id_client )
{
      cout<<"Input renting contract info:"<<endl;
      cout<<"1- start date"<<endl;
      cin>>this->startingDate;
      cout<<"2- end date"<<endl;
      cin>>this->endDate;
      cout<<"3- amount per month"<<endl;
      cin>>this->amountPerMonth;

      this->state=0;
      this->idClient=id_client;
      this->idLogement=id_logement;

      ostringstream str1;
      str1 << this->amountPerMonth;
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

      DB->getQuery("INSERT INTO `renting_contract` ( `id_logement`, `id_client`, `status`, `end_date`, `start_date`, `amount_per_month`) VALUES ( '"+idc+"', '"+idl+"', '"+state+"', '"+this->startingDate+"', '"+this->endDate+"', '"+amount+"');");
      DB->executeQuery();
}

void RentingContrat::editContrat(int id)
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
    this->idLogement=atoi(row[1]);
    this->idClient=atoi(row[2]);
    this->state=atoi(row[3]);
    this->endDate=row[4];
    this->startingDate=row[5];
    this->amountPerMonth=atof(row[5]);

    do{
      cout<<"select what you want to edit"<<endl;
      cout<<"1- end date"<<endl;
      cout<<"2- start date"<<endl;
      cout<<"3- amount per month"<<endl;
      cout<<"4- save"<<endl;
      cin>>choice;



      switch(choice){
        case 1 : cin >>x; this->endDate=x;break;
        case 2 : cin >>x; this->startingDate=x;break;
        case 3 : cin >>y; this->amountPerMonth=y;f_changed=true;break;
      }

    }
    while(choice != 4);

      ostringstream str3;
      str3 << this->state;
      string state= str3.str();

    if(f_changed){
    ostringstream str2;
    str2 << this->amountPerMonth;
    string sal= str2.str();



    DB->getQuery("UPDATE `renting_contract` SET `status` = '"+state+"', `end_date` = '"+this->endDate+"', `start_date` = '"+this->startingDate+"', `amount_per_month` = '"+sal+"' WHERE `renting_contract`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
    }else{

    DB->getQuery("UPDATE `renting_contract` SET `status` = '"+state+"', `end_date` = '"+this->endDate+"', `start_date` = '"+this->startingDate+"' WHERE `renting_contract`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();

    }

}

void RentingContrat::deleteContrat(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("DELETE FROM `renting_contract` WHERE `renting_contract`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
}

void RentingContrat::showContrat(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from renting_contract where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();

    cout<<"---------------------------------"<<endl;
    Logement l;
    l.showLogement(atoi(row[0]));

    cout<<"status: "<<row[3]<<endl;
    cout<<"end date: "<<row[4]<<endl;
    cout<<"start date : "<<row[5]<<endl;
    cout<<"amount per month: "<<row[6]<<endl;
    cout<<endl;
}

void RentingContrat::showAll()
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from renting_contract where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    while(row = DB->fetchRow()){
    cout<<"---------------------------------"<<endl;
    Logement l;
    l.showLogement(atoi(row[0]));

    cout<<"status: "<<row[3]<<endl;
    cout<<"end date: "<<row[4]<<endl;
    cout<<"start date : "<<row[5]<<endl;
    cout<<"amount per month: "<<row[6]<<endl;
    cout<<endl;
    }
}

void RentingContrat::showClosedContracts()
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from renting_contract where id = "+p_id);
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
        cout<<"end date: "<<row[4]<<endl;
        cout<<"start date : "<<row[5]<<endl;
        cout<<"amount per month: "<<row[6]<<endl;
        cout<<endl;
        }
    }

}

void RentingContrat::showPendingContracts()
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from renting_contract where id = "+p_id);
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
        cout<<"end date: "<<row[4]<<endl;
        cout<<"start date : "<<row[5]<<endl;
        cout<<"amount per month: "<<row[6]<<endl;
        cout<<endl;
        }
    }

}

void RentingContrat::signContact(int id )
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();



    DB->getQuery("UPDATE `renting_contract` SET `status` = '1'WHERE `renting_contract`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
}
