#pragma once
#include <iostream>
#include <string>
using namespace std;
class Contact {
	
public:
	string name;
	virtual string gettype()=0;
	virtual void print()=0;
	
};