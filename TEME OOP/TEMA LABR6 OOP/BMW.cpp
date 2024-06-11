#pragma once
#include "BMW.h"
#include <iostream>
#include "Weather.h"
using namespace std;

BMW::BMW()
{
    fuelCapacity = 80; 
    fuelConsumption = 15;
    avgSpeed[SUNNY] = 140;
    avgSpeed[RAIN] = 60;
    avgSpeed[SNOW] = 40;

}
unsigned int BMW::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
    if ((circuitLenght / 100 * fuelConsumption) > fuelCapacity)
        return 0;
    else
        return floor(circuitLenght / avgSpeed[condition]);
}
void BMW::printSpecs()
{
    cout << fuelCapacity << " " << fuelConsumption;
}

char* BMW::GetCarName() {
    char* s = new char[20];
    strcpy(s, "BMW");
    return s;
}
