
#include "User.h"
#include <string>
int User::getId() {
	return id;
}

void User::setId(int id)
{
	this->id = id;
}


string User::getName() {
	return name;
}

void User::setName(string name) {
	this->name = name;
}

string User::getSurname() {
	return surname;
}

void User::setSurname(string surname) {
	this->surname = surname;
}

date User::getDateOfBirth() {
	return dateOfBirth;
}

void User::setDateOfBirth(date dt) {
	this->dateOfBirth = dt;
}

void User::show() {
	cout << "Name : " << name << " " << surname << endl;
	cout << "Birth date : " << dateOfBirth.dd << "-" << dateOfBirth.mm << "-" << dateOfBirth.aa << endl;
}
User::User()
{
	cout << "Enter your name :" << endl;
	cin >> name;
	cout << "Enter your subname :" << endl;
	cin >> surname;
	cout << "Enter your birth date :(jj mm aaaa)" << endl;
	do {
		cin >> dateOfBirth.dd;
	} while ((dateOfBirth.dd<0) || (dateOfBirth.dd>32));
	do {
		cin >> dateOfBirth.mm;
	} while ((dateOfBirth.mm<0) || (dateOfBirth.mm>13));
	do {
		cin >> dateOfBirth.aa;
	} while ((dateOfBirth.aa<1950) || (dateOfBirth.aa>2019));

}

User::User(int id, string name, string surname, date dateOfBirth)
{
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->dateOfBirth = dateOfBirth;
}
