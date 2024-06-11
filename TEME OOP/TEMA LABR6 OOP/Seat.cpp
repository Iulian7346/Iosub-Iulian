#pragma once
#include "Seat.h"
#include <iostream>
#include "Weather.h"
using namespace std;

Seat::Seat()
{
    fuelCapacity = 100;
    fuelConsumption = 10;
    avgSpeed[SUNNY] = 110;
    avgSpeed[RAIN] = 70;
    avgSpeed[SNOW] = 60;

}
unsigned int Seat::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
    if ((circuitLenght / 100 * fuelConsumption) > fuelCapacity)
        return 0;
    else
        return floor(circuitLenght / avgSpeed[condition]);
}
void Seat::printSpecs()
{
    cout << fuelCapacity << " " << fuelConsumption;
}

char* Seat::GetCarName() {
    char* s = new char[20];
    strcpy(s, "Seat");
    return s;
}
