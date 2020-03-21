#include "Complexx.h"
#include<stdexcept>


double Complexx::Im()
{
	return b;
}

double Complexx::Re()
{
	return a;
}
void Complexx::SetIm(double im)
{
    this->b=im;
}
void Complexx::SetRe(double re)
{
    this->a=re;
}

Complexx Complexx::operator+(Complexx const &other)
{
    Complexx *solve = new Complexx;
	solve->a = a + other.a;
	solve->b = b + other.b;
	return *solve;
	delete solve;
}

Complexx Complexx::operator-(Complexx const & other)
{
    Complexx *solve = new Complexx;
	solve->a = a - other.a;
	solve->b = b - other.b;
	return *solve;
	delete solve;
}

Complexx Complexx::operator*(Complexx const & other)
{
    Complexx *solve = new Complexx;
	solve->a = a*other.a-b*other.b;
	solve->b = a*other.b+b*other.a;
	return *solve;
	delete solve;
}

Complexx Complexx::operator/(Complexx const & other)
{
    Complexx *solve = new Complexx;
	double w= other.a*other.a + other.b*other.b;
	if (w == 0) {
		throw std::invalid_argument("Dziel przez zero");
	}
	solve->a = (a * other.a + b * other.b)/w;
	solve->b = -(a * other.b - b * other.a)/w;
	return *solve;
	delete solve;
}

bool Complexx::operator==(Complexx const & other)
{
	return a==other.a&&b==other.b;
}

Complexx Complexx::conj()
{
    Complexx *pointer = new Complexx;
	pointer->a = a;
	pointer->b = -b;
	return *pointer;
}

double Complexx::argument()
{
	double sin, cos;
	cos = b / mod();
	sin = a / mod();
	return asin(sin);
	//return 0.0;
}

double Complexx::mod()
{
	double w = a *a + b*b;
	return sqrt(w);
}

ostream & operator<<(ostream & wyjscie, const Complexx & s)
{
	return wyjscie << s.a << "+" << s.b << "i";
}

Complexx::Complexx()
{
	this->a = 0;
	this->b = 0;
}

Complexx::Complexx(double a)
{
	this->a = a;
	this->b = 0;
}


Complexx::Complexx(double a, double b)
{
	this->a = a;
	this->b = b;
}

Complexx::~Complexx()
{
}
