#include "Number.h"
#include <cstring>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

Number::Number(const char* value, int base)
{
    sir = new char[100] {};
    strcpy(sir, value);
    nrBase = base;
    sirLen = strlen(sir);
}

Number::Number(int numar)
{
    int k = -1, oglindit = 0;

    sir = new char[100] {};
   
    nrBase = 10;

    while (numar)
    {
        oglindit = oglindit * 10 + numar % 10;
        numar = numar / 10;
    }

    while (oglindit)
    {
        sir[++k] = '0' + oglindit % 10;
        oglindit = oglindit / 10;
    }

    sir[k + 1] = '\0';

}

Number& Number::operator= (int numar) {
    int numarInitial = numar;
    int cifre[100];
    int i = 0;

    while (numar > 0) {
        cifre[i] = numar % nrBase;
        numar /= nrBase;
        i++;
    }

    char* rez = new char[i + 1];
    for (int j = i - 1; j >= 0; j--) {
        if (cifre[j] < 10) {
            rez[i - j - 1] = cifre[j] + '0';
        }
        else {
            rez[i - j - 1] = cifre[j] - 10 + 'A';
        }
    }
    rez[i] = '\0';

    delete[] sir;
    sir = rez;
    sirLen = i;

    return *this;
}

Number& Number::operator=(const char* value) {
    delete[] sir;
    sirLen = strlen(value);
    sir = new char[sirLen + 1];
    strcpy(sir, value);
    return *this;
}

Number::~Number()
{
    delete[] sir;
    sir = nullptr;

}

void Number::Print()
{
    cout << "Numarul" << " " << sir << " " << "in baza" << nrBase;
    cout << endl;
}

unsigned int Number::GetBase10Number() const //gay
{
    unsigned int result = 0, power = 1;
    int i;
    for (i = this->sirLen - 1; i >= 0; i--)
    {
        if (this->sir[i] >= '0' && this->sir[i] <= '9')
        {
            result = result + (this->sir[i] - '0') * power;
        }
        else
        {
            result = result + (this->sir[i] - 'A' + 10) * power;//pt baze > 10
        }
        power = power * this->nrBase;
    }
    return result;
}

void Number::SwitchBase(int newBase) 
{
    unsigned int base10Number = GetBase10Number();

    int nr = base10Number;
    int cif = 0;
    while (nr != 0) 
    {
        nr /= newBase;
        cif++;
    }
    char* newSir = new char[cif + 1];
    newSir[cif] = '\0';

    for (int i = cif - 1; i >= 0; i--) 
    {
        int cif = base10Number % newBase;
       
        if (cif < 10)
            newSir[i] = ('0' + cif);
        else
            newSir[i] = ('A' + cif - 10);
        base10Number /= newBase;
    }

    delete[] sir;
    sir = newSir;
    nrBase = newBase;
    sirLen = cif;
}

int Number::GetDigitsCount() {
    return sirLen;
}

int Number::GetBase() {
    return nrBase;
}

bool Number::operator<(const Number& otherNumber)
{
    return GetBase10Number() < otherNumber.GetBase10Number();
}

bool Number::operator<=(const Number& otherNumber)
{
    return GetBase10Number() <= otherNumber.GetBase10Number(); 
}

bool Number::operator>(const Number& otherNumber)
{
    return GetBase10Number() < otherNumber.GetBase10Number();
}

bool Number::operator>=(const Number& otherNumber)
{
    return GetBase10Number() < otherNumber.GetBase10Number();
}

bool Number::operator==(const Number& otherNumber)
{
    return GetBase10Number() == otherNumber.GetBase10Number();
}

 Number operator+ (const Number& num1, const Number& num2) 
 {
    int base;
    if (num1.nrBase > num2.nrBase) {
        base = num1.nrBase;
    }
    else {
        base = num2.nrBase;
    }
    int val1 = num1.GetBase10Number();
    int val2 = num2.GetBase10Number();
    int sum = val1 + val2;
    int temp = sum;
    int digits = 0;

   
    while (temp > 0) {
        temp /= base;
        digits++;
    }

   
    char result[20];
    result[digits] = '\0';
    int i = digits - 1;

    while (sum > 0) {
        int rest = sum % base;
        if (rest < 10) {
            result[i] = rest + '0';
        }
        else {
            result[i] = rest - 10 + 'A';
        }
        sum /= base;
        i--;
    }

    return Number(result, base);
}

Number operator-(const Number& num1, const Number& num2) {
    int baza;
    if (num1.nrBase > num2.nrBase) {
        baza = num1.nrBase;
    }
    else {
        baza = num2.nrBase;
    }
    int val1 = num1.GetBase10Number();
    int val2 = num2.GetBase10Number();
    int diferenta = val1 - val2;
    int nr = diferenta;
    int cif = 0;

    
    while (nr > 0) {
        nr /= baza;
        cif++;
    }

    char rez[20];
    rez[cif] = '\0';
    int i = cif - 1;

    while (diferenta > 0) {
        int rest = diferenta % baza;
        if (rest < 10) {
            rez[i] = rest + '0';
        }
        else {
            rez[i] = rest - 10 + 'A';
        }
        diferenta /= baza;
        i--;
    }

    return Number(rez, baza);
}

bool operator+=( Number& num1, Number& num2) {
    int suma = num1.GetBase10Number() + num2.GetBase10Number();
    int temp = suma;
    int cif = 0;
    while (temp > 0) 
    {
        temp /= num1.nrBase;
        cif++;
    }

    char rezultat[20];
    rezultat[cif] = '\0';
    int i = cif - 1;

    while (suma > 0) {
        int rest = suma % num1.nrBase;
        if (rest < 10) {
            rezultat[i--] = rest + '0';
        }
        else {
            rezultat[i--] = rest - 10 + 'A';
        }
        suma /= num1.nrBase;
    }

    delete[] num1.sir;
    num1.sir = new char[cif + 1];
    strcpy(num1.sir, rezultat);
    num1.sirLen = cif;

    return true;

}

Number& Number::operator--() {
    if (sirLen > 0) {
        for (int i = 0; i < sirLen - 1; ++i) {
            sir[i] = sir[i + 1];
        }
        sirLen--;
        sir[sirLen] = '\0';
    }
    return (*this);
}

Number Number::operator--(int) {
    
    if (sirLen > 0) {
        sirLen--;
        sir[sirLen] = '\0';
    }
    return (*this);
}
