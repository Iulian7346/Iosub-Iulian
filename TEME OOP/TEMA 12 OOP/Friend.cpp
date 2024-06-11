#pragma once
#include "Friend.h"

Friend::Friend(string number, string birth, string address, string nume)
{
	this->number = number;
	this->birth = birth;
	this->address = address;
	this->name = nume;
}

string Friend::gettype()
{
	return "friend";
}

void Friend::print()
{
	cout << "number: " << number << " birth: " << birth << " address: " << address<< endl;
}
