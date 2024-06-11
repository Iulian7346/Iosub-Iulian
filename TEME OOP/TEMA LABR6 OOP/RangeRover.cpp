#pragma once
#include "RangeRover.h"
#include <iostream>
#include "Weather.h"
using namespace std;

RangeRover::RangeRover()
{
    fuelCapacity = 130;
    fuelConsumption = 10;
    avgSpeed[SUNNY] = 60;
    avgSpeed[RAIN] = 180;
    avgSpeed[SNOW] = 300;

}
unsigned int RangeRover::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
    if ((circuitLenght / 100 * fuelConsumption) > fuelCapacity)
        return 0;
    else
        return floor(circuitLenght / avgSpeed[condition]);
}
void RangeRover::printSpecs()
{
    cout << fuelCapacity << " " << fuelConsumption;
}

char* RangeRover::GetCarName() {
    char* s = new char[20];
    strcpy(s, "RangeRover");
    return s;
}
