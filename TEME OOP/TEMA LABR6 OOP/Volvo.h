#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
    Volvo();
    unsigned int GetRaceTime(unsigned int circuitLenght, Weather condition);
    char* GetCarName();
    void printSpecs();
};