#pragma once
#include "Car.h"
class Seat : public Car
{
public:
    Seat();
    unsigned int GetRaceTime(unsigned int circuitLenght, Weather condition);
    void printSpecs();
    char* GetCarName();
};