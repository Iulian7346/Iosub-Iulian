#include <iostream>

using namespace std;

float KelvinToCelsius(long double k) {
    return k - 273.15;
}

float FahrenheitToCelsius(long double f) {
    return (f - 32) * 5 / 9;
}

int main() {
    float a = KelvinToCelsius(300);
    float b = FahrenheitToCelsius(120);

    cout << "Temperaturi in Celsius:\n";
    cout << "300 Kelvin sunt " << a << " grade Celsius.\n";
    cout << "120 Fahrenheit sunt " << b << " grade Celsius.\n";

    return 0;
}
