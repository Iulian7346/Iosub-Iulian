
#ifndef NUMBER_H
#define NUMBER_H

class Number {
private:
    char* sir;
    int nrBase;
    unsigned int sirLen;

public:
    Number(const char* value, int base);
    Number(int numar);
    ~Number();

    Number& operator=(int numar);
    Number& operator=(const char* value);

    void Print();
    unsigned int GetBase10Number() const;
    void SwitchBase(int newBase);
    int GetDigitsCount();
    int GetBase();

    bool operator<(const Number& otherNumber);
    bool operator<=(const Number& otherNumber);
    bool operator>(const Number& otherNumber);
    bool operator>=(const Number& otherNumber);
    bool operator==(const Number& otherNumber);

    friend Number operator+ (const Number& num1, const Number& num2);
    friend Number operator- (const Number& num1, const Number& num2);
    friend bool operator+= (Number& num1, Number& num2);
    friend Number& operator--();
    friend Number operator--(int value);
  

};



#endif /* NUMBER_H */
