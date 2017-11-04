#include "fun.h"
#include <stdlib.h>

double S(double x, double x_0, double h, std::vector<double> y, Function function) {
  int i = (x-x_0)/h;
  return Si(x, x_0+(i+1)*h, x_0+i*h, y[i+1], y[i], h, function);
}

double Si(double x, double xi, double xi_1, double yi, double yi_1, double h, Function function) {
  double t1 = xi-x, t2 = x-xi_1;
  return (t1*t1*(2*t2+h)*function.F(xi_1))/(h*h*h)+(t2*t2*(2*t1+h)*function.F(xi))/(h*h*h)+(t1*t1*t2*yi_1)/(h*h)+(t2*t2*(-t1)*yi)/(h*h);
}

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

double Round(double X, double Delta) {
  if (Delta <= 1E-9) {
    exit(1);
  }
  if (X > 0.0)
    return (Delta*(long((X/Delta)+0.5)));
  else
    return (Delta*(long((X/Delta)-0.5)));
}
