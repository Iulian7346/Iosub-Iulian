#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
    RangeRover();
    unsigned int GetRaceTime(unsigned int circuitLenght, Weather condition);
    void printSpecs();
    char* GetCarName();
};