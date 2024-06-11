#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
using namespace std;
class AddressBook
{
	vector <Contact*> contacte;


public:
	void AddContact(Contact* toAdd);
	void DeleteContact(string nume);
	bool SearchByName(string nume);
	void FriendList();
};

