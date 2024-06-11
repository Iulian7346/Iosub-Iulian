#pragma once
#include "Acquintance.h"
#include <string>
#include <vector>
using namespace std;

Acquintance::Acquintance(string number, string nume)
{
	this->number = number;
	this->name = nume;
}

string Acquintance::gettype()
{
	return "Acquintance";
}

void Acquintance::print()
{
	cout << "number: " << number << endl;
}