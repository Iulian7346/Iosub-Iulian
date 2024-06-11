#pragma once
#include "Car.h"
class BMW : public Car
{
public:
    BMW();
    unsigned int GetRaceTime(unsigned int circuitLenght, Weather condition);
    void printSpecs();
    char* GetCarName();

};