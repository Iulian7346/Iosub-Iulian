#include <iostream>
#include "Math.h"
using namespace std;
int main() {
    
    cout << "Add(3, 5): " << Math::Add(3, 5) << endl;
    cout << "Add(1.5, 2.5): " << Math::Add(1.5, 2.5) << endl;
    cout << "Add(4, 6, 8): " << Math::Add(4, 6, 8) << endl;
    cout << "Add(5, 1, 2, 3, 4, 5): " << Math::Add(5, 1, 2, 3, 4, 5) << endl;

    const char* str1 = "127";
    const char* str2 = "37";
    char* str3 = Math::Add(str1, str2);
    if (str3 != nullptr) {
        cout << "Add(\"" << str1 << "\", \"" << str2 << "\"): " << str3 << endl;
        delete[] str3;
    }
    else {
        cout << "Add(\"" << str1 << "\", \"" << str2 << "\"): nullptr" << endl;
    }

    
    cout << "Mul(4, 6): " << Math::Mul(4, 6) << endl;
    cout << "Mul(2.5, 3.5): " << Math::Mul(2.5, 3.5) << endl;
    cout << "Mul(2.5, 3.5, 1.5): " << Math::Mul(2.5, 3.5, 1.5) << endl;

   

    return 0;
}