#include "Entitate.h"
#include <cmath>

Entitate::Entitate() {
    this->realNumber = 0;
    this->imaginaryNumber = 0;
}

Entitate::Entitate(float real, float imaginary) {
    this->realNumber = real;
    this->imaginaryNumber = imaginary;
}

Entitate::Entitate(const Entitate& nr) {
    this->realNumber = nr.realNumber;
    this->imaginaryNumber = nr.imaginaryNumber;
}

float Entitate::getReal() {
    return this->realNumber;
}

float Entitate::getImaginary() {
    return this->imaginaryNumber;
}

void Entitate::setReal(float real) {
    this->realNumber = real;
}

void Entitate::setImaginary(float imaginary) {
    this->imaginaryNumber = imaginary;
}

float Entitate::absoluteValue() {
    return sqrt(pow(this->realNumber, 2) + pow(this->imaginaryNumber, 2));
}

Entitate::~Entitate() {

}

Entitate& Entitate::operator=(const Entitate& nr) {
    this->setReal(nr.realNumber);
    this->setImaginary(nr.imaginaryNumber);
    return *this;
}

bool Entitate::operator==(const Entitate& nr) {
    return this->realNumber == nr.realNumber and this->imaginaryNumber == nr.imaginaryNumber;
}


Entitate Entitate::operator+(Entitate nr) {
    return Entitate(this->realNumber + nr.realNumber, this->imaginaryNumber + nr.imaginaryNumber);
}

Entitate Entitate::operator*(Entitate nr) {
    return Entitate(this->realNumber * nr.realNumber + (-this->imaginaryNumber * nr.imaginaryNumber),
        this->realNumber * nr.imaginaryNumber + nr.realNumber * this->imaginaryNumber);
}

Entitate Entitate::operator-(Entitate nr) {
    return Entitate(this->realNumber - nr.realNumber, this->imaginaryNumber - nr.imaginaryNumber);
}


Entitate Entitate::conjugate() {
    return Entitate(this->realNumber, -1 * this->imaginaryNumber);
}

ostream& operator<<(ostream& os, Entitate& c) {
    if (c.getImaginary() < 0) {
        if (c.imaginaryNumber == -1) {
            os << c.getReal() << " - i";
        }
        else {
            os << c.getReal() << " - " << -1 * c.getImaginary() << "i";
        }
    }
    else {
        if (c.imaginaryNumber == 1) {
            os << c.getReal() << " + i";
        }
        else {
            os << c.getReal() << " + " << c.getImaginary() << "i";
        }
    }
    return os;
}

istream& operator>>(istream& is, Entitate& c) {
    cout << "Partea reala: \n";
    is >> c.realNumber;
    cout << "Partea imaginara: \n ";
    is >> c.imaginaryNumber;
    if (c.imaginaryNumber < 0) {
        if (c.imaginaryNumber == -1) {
            cout << c.getReal() << " - i" << endl;
        }
        else {
            cout << c.getReal() << " - " << -1 * c.getImaginary() << "i" << endl;
        }
    }
    else {
        if (c.imaginaryNumber == 1) {
            cout << c.getReal() << " + i" << endl;
        }
        else {
            cout << c.getReal() << " + " << c.getImaginary() << "i" << endl;
        }
    }
    return is;
}