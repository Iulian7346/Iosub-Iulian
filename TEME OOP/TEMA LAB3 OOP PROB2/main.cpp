#include<iostream>
#include "Canvas.h"
using namespace std;

int main() {
   
    Canvas canvas(30, 30);

    canvas.DrawRect(5, 2, 15, 7, '#');
    canvas.FillRect(8, 4, 10, 6, '@');
    canvas.FillRect(3, 12, 19, 25, '9');
    canvas.FillCircle(18, 12, 4, '.');
    canvas.Print();
    canvas.Clear();

    cout << endl;
   
    canvas.DrawCircle(10, 12, 10, '$');
    canvas.FillCircle(6, 8, 2, '&');
    canvas.FillCircle(6, 16, 2, '&');
    canvas.DrawCircle(14, 12, 3, '%');
    canvas.SetPoint(5, 9, '.');
    canvas.SetPoint(5, 17, '.');
    canvas.Print();
    canvas.Clear();

    canvas.DrawLine(3, 6, 11, 22, 'B');
    canvas.DrawLine(1, 12, 18, 20, 'A');
    canvas.Print();
    canvas.Clear();
    
    return 0;
}