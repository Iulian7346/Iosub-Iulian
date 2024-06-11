#pragma once
#include "Fiat.h"
#include <iostream>
#include "Weather.h"
using namespace std;

Fiat::Fiat()
{
    fuelCapacity = 50;
    fuelConsumption = 20;
    avgSpeed[SUNNY] = 110;
    avgSpeed[RAIN] = 100;
    avgSpeed[SNOW] = 90;

}
unsigned int Fiat::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
    if ((circuitLenght / 100 * fuelConsumption) > fuelCapacity)
        return 0;
    else
        return floor(circuitLenght / avgSpeed[condition]);
}
void Fiat::printSpecs()
{
    cout << fuelCapacity << " " << fuelConsumption;
}

char* Fiat::GetCarName()
{
    char* s = new char[20];
    strcpy(s, "Fiat");
    return s;
}