#ifndef _USER_H
#define _USER_H
#include "date.h"
#include <iostream>
using namespace std;
class User {
public:
	User();
	User(int, string, string, date);
	int getId();
	void setId(int);
	string getName();


	void setName(string);

	string getSurname();

	void setSurname(string);

	date getDateOfBirth();

	void setDateOfBirth(date);
	void show();
private:
	int id;
	string name;
	string surname;
	date dateOfBirth;
};

#endif //_USER_H
