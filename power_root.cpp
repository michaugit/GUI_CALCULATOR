#include "power_root.h"
#include <math.h>

using namespace std;

double powerFunc(double number, double power){
    return pow(number, power);
}

double rootFunc(double number, double root){
   return pow(number, (1 / root));
}

double cbrtCalc(double number){
    return cbrt(number);
}
