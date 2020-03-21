#include "basic_operations.h"

double plus(double first_number, double second_number)
{
    return first_number+second_number;
}

double minus(double from_number, double what_number)
{
    return from_number-what_number;
}

double multiply(double first_number, double second_number)
{
    return first_number*second_number;
}

double divide(double what, double by)
{
    if(by==0) throw DivideByZero();
    return what/by;
}

double factorial(double number)
{
    if(number<0) throw NegativeFactorial();
     long long ret=1;
    for(int i=1; i<=number; i++){
        ret*=i;
    }
    return ret;
}

double percent(double percent, double from)
{
    return from*(percent/100);
}

