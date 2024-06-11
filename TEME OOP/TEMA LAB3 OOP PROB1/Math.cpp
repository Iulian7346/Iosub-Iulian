#include "Math.h"

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return static_cast<int>(a + b);
}

int Math::Add(double a, double b, double c) {
    return static_cast<int>(a + b + c);
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return static_cast<int>(a * b);
}

int Math::Mul(double a, double b, double c) {
    return static_cast<int>(a * b * c);
}

int Math::Add(int count, ...) {
    int sum = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum;
}

char* Math::Add(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) {
        return nullptr;
    }

    int n = strlen(str1);
    int m = strlen(str2);
    int maxLength = (n > m) ? n : m;
    maxLength++;

    char* str3 = new char[maxLength + 1];
    str3[maxLength] = '\0';

    int carry = 0;
    int i = n - 1;
    int j = m - 1;
    int res = maxLength - 1;

    while (i >= 0 || j >= 0) {
        int c1 = 0;
        if (i >= 0) {
            c1 = str1[i] - '0';
        }

        int c2 = 0;
        if (j >= 0) {
            c2 = str2[j] - '0';
        }

        int sum = c1 + c2 + carry;
        carry = sum / 10;
        str3[res] = '0' + (sum % 10);
        i--;
        j--;
        res--;
    }

    if (carry > 0) {
        str3[res] = '0' + carry;
    }

    if (str3[0] == '0') {
        char* newRes = new char[maxLength];
        strcpy(newRes, str3 + 1);
        delete[] str3;
        str3 = newRes;
    }

    return str3;
}
