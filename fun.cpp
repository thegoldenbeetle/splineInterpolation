#include "fun.h"
#include <stdlib.h>
#include <math.h>
#include <stdexcept>

Function::Function(std::vector<double> coefficients) {
    if (coefficients.size() != degree + 1)
        throw std::length_error("Wrong degree!\n");
    else
        this -> coefficients = coefficients;
}

double Function::F(double x) {
    double res = 0;
    for (unsigned short i = 0; i < degree + 1; i++) {
        res += coefficients[i] * pow(x, i);
    }
    return res;
}

double Function::DiffrF(double x) {
    double res = 0;
    for (unsigned short i = 1; i < degree + 1; i++) {
        res += i * coefficients[i] * pow(x, i - 1);
    }
    return res;
}

double Function::Diffr2F(double x) {
    double res = 0;
    for (unsigned short i = 2; i < degree + 1; i++) {
        res += i * (i - 1) * coefficients[i] * pow(x, i - 2);
    }
    return res;
}
