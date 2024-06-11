#pragma once
#include <iostream>
#include <string>
#include "Contact.h"
using namespace std;

class Acquintance: public Contact
{

public:
	string number;
	Acquintance(string number, string nume);
	string gettype();
	void print();
};

