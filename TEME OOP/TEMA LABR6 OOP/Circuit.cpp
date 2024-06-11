#pragma once
#include "Circuit.h"
#include <iostream>
#include "Volvo.h"
#include "BMW.h"
#include "RangeRover.h"
#include "Fiat.h"
#include "Seat.h"
using namespace std;

Circuit::Circuit(unsigned int nrDesiredCars)
{
    cars = new Car* [nrDesiredCars];
}

void Circuit::SetLenght(unsigned int lenght)
{
    this->lenght = lenght;
}
void Circuit::SetWeather(Weather weather)
{
    this->weather = weather;
}
void Circuit::AddCar(Car* car)
{
    cars[nrCars++] = car;
}
void Circuit::Race()
{
    unsigned int i,j;
    Car* aux;

    for (i = 0; i < nrCars-1; i++)
        for (j = i + 1; j < nrCars; j++)
        {
            if (cars[i]->GetRaceTime(lenght, weather) > cars[j]->GetRaceTime(lenght, weather))
            {
                aux = cars[i];
                cars[i] = cars[j];
                cars[j] = aux;
            }
        }

}

void Circuit::ShowFinalRanks()
{
    int  j = 0; 
    int i;
    while (cars[j]->GetRaceTime(lenght, weather) == 0)j++;

    cout << "PODIUM" << endl;

    for (i = j; i < nrCars; i++)
    {
        cout << "locul " << i - j+1 << ": " << cars[i]->GetCarName() << ' ' << cars[i]->GetRaceTime(lenght, weather) << endl;
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    cout << "NU AU AJUNS LA FINISH"<<endl;

    int  j = 0;
    while (cars[j]->GetRaceTime(lenght, weather) == 0)
    {
        cout << cars[j]->GetCarName() << endl;
        j++;
    }
}
