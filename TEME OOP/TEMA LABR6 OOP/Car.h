#include "Weather.h"
#pragma once
class Car
{
public:
    unsigned int fuelCapacity;
    unsigned int fuelConsumption;
    unsigned int avgSpeed[3]; //1 sunny 2 rainy 3 snow
    virtual unsigned int GetRaceTime(unsigned int circuitLenght, Weather condition) = 0;
    virtual char* GetCarName() = 0;
};
