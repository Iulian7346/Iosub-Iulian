#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <cstring>
#include <initializer_list>

using namespace std;

int main()
{
	cout << "construit cu min max" << endl;
	Sort s1(6, 1, 190);
	s1.Print(); 
	s1.BubbleSort(); 
	s1.Print();
	cout << endl;

	cout << "construit cu lista initializare" << endl;
	Sort s2({ 7, 34, 6, 1, 19, 98, 3, 25, 7, 4 });
	s2.Print(); 
	s2.InsertSort(); 
	s2.Print();
	cout << endl;

	cout << "construit cu vector" << endl;
	int v[11] = { 7, 3, 12, 5, 99, 8, 36, 14, 2, 45, 6 };
	Sort s3(v, 10);
	s3.Print(); 
	s3.QuickSort(); 
	s3.Print();
	cout << endl;

	cout << "constuit cu variadic parameters" << endl;
	Sort s4(5, 3, 6, 7, 2, 33);
	s4.Print(); 
	s4.BubbleSort(); 
	s4.Print();
	cout << endl;

	cout << "construit din sir de caractere" << endl;
	char numere[] = "87,9,21,5,76,3,18,3,55,12,4,32,1";
	cout << numere << endl;
	Sort s5(numere);
	s5.QuickSort(); s5.Print();
}
