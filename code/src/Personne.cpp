#include "Personne.h"
#include <iostream>
#include <string>
#include "date.h"
using namespace std;



Personne::Personne(string name, string subname, string birthDate) {
this->name=name;
this->subname=subname;
this->birthDate=birthDate;
}

Personne::Personne() {
this->id=1;
}
Personne::~Personne(){
}


