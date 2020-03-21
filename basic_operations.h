#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

double plus(double first_number, double second_number);
double minus(double from_number, double what_number);
double multiply(double first_number, double second_number);
double divide(double what, double by);

double factorial(double number);
double percent(double percent, double from);

//wyjatki:
class DivideByZero{};
class NegativeFactorial{};



#endif // BASIC_OPERATIONS_H
