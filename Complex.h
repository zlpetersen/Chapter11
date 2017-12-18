#pragma once
#include <iostream>
class Complex
{
private:
    double a_, i_;
public:
    Complex();
    Complex(double a, double i);
    friend std::istream& operator >> (std::istream& is, Complex& c);
    friend std::ostream& operator << (std::ostream& os, const Complex& c);
    friend Complex operator + (const Complex& c1, const Complex& c2);
    friend Complex operator - (const Complex& c1, const Complex& c2);
    friend Complex operator * (const Complex& c1, const Complex& c2);
    friend Complex operator * (double n, const Complex& c1);
    friend Complex operator - (const Complex& c1);
};

