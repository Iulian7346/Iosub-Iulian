//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

//==============SORTAREA MEA===================

/*template <class T>
void bubbleSort(T v[], int n) {
    bool sorted;
    do {
        sorted = true;
        int i = 1; 

        if (n > 2)
        {
            while (i < n - 2) 
            {
                if (v[i] > v[i + 1]) {
                    T aux = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux;
                    sorted = false;
                }
                else
                    if (v[i] == v[i + 1])
                    {
                        sorted = true;
                    }
                    else
                    {
                        i++; 
                    }
                i++;
            }
        }
        
    } while (!sorted);
}*/

//=================SORTAREA COLEGULUI====================================
#include "gtest/gtest.h"

template <class T>
void Sortare(T arr[], unsigned int& n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j];
                arr[j + 1] = temp;
                arr[j] = arr[j + 1];
            }
        }
    }
    n--;
}