#pragma once
#include <iostream>
#include <string>
#include "Contact.h"
using namespace std;
class Friend: public Contact
{
	
public:
	string birth;
	string number;
	string address;
	Friend(string number, string birth, string address, string nume);
	string gettype();
	void print();
};

