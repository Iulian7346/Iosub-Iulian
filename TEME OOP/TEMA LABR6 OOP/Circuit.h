#pragma once
#include "Weather.h"
#include "Car.h"
class Circuit
{
private:
    unsigned int lenght;
    Weather weather;
    //Car* cars[20];
    Car** cars;
    unsigned int nrCars = 0;
public:
    Circuit(unsigned int nrDesiredCars);
    void SetLenght(unsigned int lenght);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};