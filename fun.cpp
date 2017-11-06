#include "fun.h"
#include <stdlib.h>

Function::Function(std::vector<double> coefficients) {
    this -> coefficients = coefficients;
}

double Function::F(double x) {
    return coefficients[0]*(x*x*x) + coefficients[1]*(x*x) + coefficients[2]*x + coefficients[3];
}

double Function::DiffrF(double x) {
    return 3*coefficients[0]*(x*x) + 2*coefficients[1]*x + coefficients[2];
}

double Function::Diffr2F(double x) {
    return 6*coefficients[0]*x + 2*coefficients[1];
}
