#pragma once
#include "AddressBook.h"
#include "Contact.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;

void AddressBook::AddContact(Contact* toAdd)
{
	contacte.push_back(toAdd);
}

void AddressBook::DeleteContact(string nume)
{
	vector <Contact*> newcontacte;

	for (auto i : contacte)
		if (i->name != nume)
			newcontacte.push_back(i);

	contacte = newcontacte;
}

bool AddressBook::SearchByName(string nume)
{

	for (auto i : contacte)
		if (i->name == nume)
			return true;
	return false;
}

void AddressBook::FriendList()
{

	cout << "FRIEND LIST: " << endl;
	for (auto i : contacte)
		if (i->gettype() == "friend")
			i->print();

}
