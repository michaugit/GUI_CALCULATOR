#pragma once
#include <iostream>
#include<ostream>
#include<stdexcept>
#include<cmath>


using ::std::ostream;
class Complexx
{
	double a, b;
public:
	double Im();
	double Re();
    void SetIm(double im);
    void SetRe(double re);
    Complexx operator+(Complexx const &other);
    Complexx operator-(Complexx const &other);
    Complexx operator*(Complexx const &other);
    Complexx operator/(Complexx const &other);
    bool operator==(Complexx const &other);
    Complexx conj();
	double argument();
	double mod();
    friend ostream& operator<< (ostream &wyjscie, const Complexx &s);
    Complexx(double a, double b);
    Complexx();
    Complexx(double a);
    ~Complexx();
};
