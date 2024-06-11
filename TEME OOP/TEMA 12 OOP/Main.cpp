#pragma once
#include <iostream>
#include<vector>
#include <string>
#include "AddressBook.h"
#include "Colleague.h"
#include "Contact.h"
#include "Friend.h"
#include "Acquintance.h"

using namespace std;
int main()
{
	AddressBook adr;

	adr.AddContact(new Friend("0734 569 992", "2002.08.17", "Antarctica", "Marius"));
	adr.AddContact(new Friend("0788 888 000", "1940.02.31", "bulevardul unirii, bloc 6", "Anton"));
	adr.AddContact(new Colleague("0799 9543 532", "Amazon", "Sydney, Australia", "Chloe"));
	adr.AddContact(new Acquintance("0777 777 777","Just a guy"));
	adr.FriendList();
	adr.DeleteContact("Anton");

	adr.FriendList();

	string nume_cautare;
	nume_cautare = "Just a guy";

	if (adr.SearchByName(nume_cautare))
		cout << "found " << nume_cautare << endl;
	else
		cout << "couldn't find " << nume_cautare<< endl;

	nume_cautare = "Alex";

	if (adr.SearchByName(nume_cautare))
		cout << "found " << nume_cautare << endl;
	else
		cout << "couldn't find " << nume_cautare<<endl;


	return 0;
}