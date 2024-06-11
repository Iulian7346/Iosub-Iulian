#pragma once
#include <iostream>
#include <string>
#include "Contact.h"
using namespace std;
class Colleague: public Contact
{
	
public:
	string company;
	string number;
	string address;
    Colleague(string number, string company, string address, string nume);
	
	string gettype();
	void print();
};

