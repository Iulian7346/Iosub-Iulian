#pragma once
#include "Volvo.h"
#include <iostream>
#include "Weather.h"
using namespace std;

Volvo::Volvo()
{
    fuelCapacity = 80; //litri
    fuelConsumption = 12;//litri la 100 km
    avgSpeed[Weather::SUNNY] = 130; //ambele scrieri sunt corecte
    avgSpeed[RAIN] = 90;
    avgSpeed[SNOW] = 70;

}
unsigned int Volvo::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
    if ((circuitLenght / 100 * fuelConsumption) > fuelCapacity)
        return 0;
    else
        return floor(circuitLenght / avgSpeed[condition]);
}
void Volvo::printSpecs()
{
    cout << fuelCapacity << " " << fuelConsumption;
}

char* Volvo::GetCarName()
{
    char* s = new char[20];
    strcpy(s, "Volvo");
    return s;
}