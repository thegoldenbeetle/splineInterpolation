#include "fun.h"
#include <stdlib.h>

double S(double x, double x_0, double h, double *y) {
  int i = (x-x_0)/h;
  return Si(x, x_0+(i+1)*h, x_0+i*h, y[i+1], y[i], h);
}

double Si(double x, double xi, double xi_1, double yi, double yi_1, double h) {
  double t1 = xi-x, t2 = x-xi_1;
  return (t1*t1*(2*t2+h)*F(xi_1))/(h*h*h)+(t2*t2*(2*t1+h)*F(xi))/(h*h*h)+(t1*t1*t2*yi_1)/(h*h)+(t2*t2*(-t1)*yi)/(h*h);
 // return (F(xi_1)*t1 + F(xi)*t2)/h + (yi_1*(t1*t1*t1-h*h*t1)+yi*(t2*t2*t2-h*h*t2))/6*h;
}

double F(double x) {
  return x*x*x+2*x*x+x+3;
}

double Difr_F(double x) {
  return 3*x*x+4*x+1;
}

double Difr2_F(double x) {
  return 6*x+4;
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