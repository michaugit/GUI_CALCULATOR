#include "equations.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

std::string solve_linear_equation(double a, double b){
    if(a!=0){
        double solution = -b/a;
        std::string message = "Rozwiązanie to x = " + std::to_string(solution);
        return message;
    }
    else
        if(b==0)
            return "nieskonczenie wiele rozwiazan";
        else
            return "równanie sprzeczne";
}

std::string solve_quadratic_equation(double a, double b, double c){

    const double EPS   = 0.0000000001; // dokładność porównania z zerem

    double delta,x1,x2;

    if(fabs(a) < EPS)
        return "To nie jest rownanie kwadratowe\n";
    else
    {
        delta = b * b - 4 * a * c;
        if(fabs(delta) < EPS) delta = 0;
        if(delta < 0)
            return "Brak pierwiastkow rzeczywistych\n";
        else
        {
            x1 = (-b + sqrt(delta)) / 2 / a;
            x2 = (-b - sqrt(delta)) / 2 / a;

            std::string solution;
            solution = "Rozwiązanie to: \n x1 = " + std::to_string(x1) + ", x2 = " + std::to_string(x2);
            return solution;

        }
    }
}

// funkcja wylicza pierwiastek 3 stopnia
//--------------------------------------

inline double qrt(double x)
{
    return fabs(x) == 0 ? 0 : (x > 0 ? exp(log(x)/3) : -exp(log(-x)/3));
}


std::string solve_cubic_equation(double a, double b, double c, double d){

    const double EPS   = 0.0000000001; // dokładność porównania z zerem

    double f,g,h,i,j,k,m,n,p,x1,x2,x3;
    std::string solution;

    if(fabs(a) < EPS)
        return "To nie jest rownanie szescienne\n";
    else {
            // Obliczamy współczynniki pomocnicze f,g i h

            f = (c - b*b/3/a)/a;
            g = ((2*b*b/9/a - c)/a*b/3 + d)/a;
            h = g*g/4 + f*f*f/27;

            // Sprawdzamy kolejne warunki

            if((fabs(f) < EPS) && (fabs(g) < EPS)){

                // Pierwiastek potrójny

                x1 = x2 = x3 = - qrt(d/a);

                solution = "Pierwiastek potrójny: x1 = " + std::to_string(x1);
                return solution;
            }
            else if(h >= EPS){
                // Jeden pierwiastek rzeczywisty

                x1 = qrt(-g/2 + sqrt(h)) + qrt(-g/2 - sqrt(h)) - b/3/a;
                solution = "Jeden pierwiastek rzeczyiwsty: x1 = " + std::to_string(x1);
                return solution;
            }
            else{
                // Trzy pierwiastki rzeczywiste

                i  = sqrt(g*g/4 - h);
                j  = qrt(i);
                k  = acos(-g/2/i);
                m  = cos(k/3);
                n  = sqrt(3)*sin(k/3);
                p  = -b/3/a;
                x1 = 2*j*m + p;
                x2 = -j*(m + n) + p;
                x3 = -j*(m - n) + p;

                solution = "Trzy pierwiastki rzeczywiste: \n x1 = " + std::to_string(x1) + ", x2 = " + std::to_string(x2) + ", x2 = " + std::to_string(x3);
                return solution;
            }
        }
    }