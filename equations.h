#ifndef INPG_EQUATIONS_H
#define INPG_EQUATIONS_H

#include<string>

//the function below solves linear equations as: ax + b = 0
std::string solve_linear_equation(double a, double b);

//the function below solves linear equations as: ax^2 + bx + c = 0
std::string solve_quadratic_equation(double a, double b, double c);

//the function below solves linear equations as: ax^3 + bx^2 + cx + d = 0
std::string solve_cubic_equation(double a, double b, double c, double d);

#endif //INPG_EQUATIONS_H
