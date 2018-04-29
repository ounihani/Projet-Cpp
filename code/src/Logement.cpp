#include "Logement.h"
#include <string>
#include <sstream>



using namespace std;
void Logement::addLogement(int id_owner)
{

      cout<<"Input Logement info"<<endl;
      cout<<"1- Type the title"<<endl;
      cin>>this->title;
      cout<<"1- Type the description of the logement"<<endl;
      cin>>this->descrip;
      ostringstream str1;
      str1 << id_owner;
      string id_o= str1.str();

      DB->getQuery("INSERT INTO `logement` (`id_prop`, `title`, `description`) VALUES ( '"+id_o+"', '"+this->title+"', '"+this->descrip+"');");
      DB->executeQuery();

}

void Logement::editLogement(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from logement where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();
    this->descrip=row[2];

    cout<<"the new description is :"<<endl<<this->descrip<<endl;
    cout<<"input the new description"<<endl;
    getline (std::cin,this->descrip);
    DB->getQuery("UPDATE `logement` SET `description` = '"+this->descrip+"' WHERE `logement`.`id` = "+p_id);
    DB->executeQuery();


}

void Logement::deleteLogement(int id)
{
    ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("DELETE FROM `logement` WHERE `logement`.`id` = "+p_id);
    DB->executeQuery();
    DB->getResult();
}

void Logement::showLogement(int id)
{
 ostringstream str1;
    str1 << id;
    string p_id = str1.str();

    DB->getQuery("select * from logement where id = "+p_id);
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;
    row = DB->fetchRow();

    cout<<"---------------------------------"<<endl;
    cout<<"owner identifier : "<<row[1]<<endl;
    cout<<"title: "<<row[2]<<endl;
    cout<<"description: "<<row[3]<<endl;
    cout<<endl;
}

void Logement::showAll()
{
DB->getQuery("select * from logement");
    DB->executeQuery();
    DB->getResult();
    MYSQL_ROW row ;

    while(row = DB->fetchRow()){
    cout<<"---------------------------------"<<endl;
    cout<<"Owner identifier: "<<row[1]<<endl;
    cout<<"title: "<<row[2]<<endl;
    cout<<"Description: "<<row[3]<<endl;
    cout<<endl;
    }
}

Logement::Logement()
{

}

Logement::~Logement()
{
 //delete this->DB;
}
