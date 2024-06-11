#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <initializer_list>

using namespace std;
class Sort
{
    
    int* vec;
    int n;

public:
    
    Sort();
    Sort(int lungime, int min, int max);
    Sort(const initializer_list<int> list);
    Sort(int vect[], int lung);
    Sort(int count, ...);
    Sort(char text[]);

    void InsertSort(bool ascendent = false);
    int partition(int low, int high, bool ascendent);
    void QuickSortHelper(int low, int high, bool ascendent);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

