#pragma once

#include <iostream>
using namespace std;

class Entitate {
private:
    float realNumber;
    float imaginaryNumber;
public:
    Entitate();
    Entitate(float real, float imaginary);
    Entitate(const Entitate& nr);
    ~Entitate();
    // Getter
    float getReal();
    float getImaginary();
    // Setter
    void setReal(float real);
    void setImaginary(float imaginary);

    float absoluteValue();
    Entitate conjugate();

    // Operators
    Entitate& operator=(const Entitate& nr);
    bool operator==(const Entitate& nr);
    Entitate operator+(Entitate nr);
    Entitate operator*(Entitate nr);
    Entitate operator-(Entitate nr);
    friend ostream& operator<<(ostream& os, Entitate& c);
    friend istream& operator>>(istream& is, Entitate& c);
};