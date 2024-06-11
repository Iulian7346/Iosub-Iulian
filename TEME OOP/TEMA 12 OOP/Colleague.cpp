#pragma once
#include "Colleague.h"

Colleague::Colleague(string number, string company, string address, string nume)
{
    this->number = number;
    this->company = company;
    this->address = address;
    this->name = nume;
}


string Colleague::gettype()
{
    return "colleague";
}

void Colleague::print()
{
    cout << "number: " << number << " company: " << company << " address: " << address;
}