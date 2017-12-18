#include "Complex.h"



Complex::Complex()
{
    a_ = i_ = 0;
}


Complex::Complex(double a, double i)
{
    a_ = a;
    i_ = i;
}


std::istream& operator >> (std::istream& is, Complex& c)
{
	std::cout << "real: ";
	is >> c.a_;
	std::cout << "imaginary: ";
	is >> c.i_;
    return is;
}


std::ostream& operator << (std::ostream& os, const Complex& c)
{
    os << "(" << c.a_ << ", " << c.i_ << "i)";
    return os;
}


Complex operator + (const Complex& c1, const Complex& c2)
{
    Complex sum(c1.a_ + c2.a_, c1.i_ + c2.i_);
    return sum;
}


Complex operator - (const Complex& c1, const Complex& c2)
{
    Complex diff(c1.a_ - c2.a_, c1.i_ - c2.i_);
    return diff;
}


Complex operator * (const Complex& c1, const Complex& c2)
{
    Complex mult(c1.a_ * c2.a_ - c1.i_ * c2.i_, c1.a_ * c2.i_ + c1.i_ * c2.a_);
    return mult;
}


Complex operator * (double n, const Complex& c1)
{
    Complex mult(n * c1.a_, n * c1.i_);
    return mult;
}


Complex operator - (const Complex& c1)
{
    Complex result(-c1.a_, -c1.i_);
    return result;
}
