#ifndef FUN
#define FUN
#include <vector>

class Function {
public:
    Function (std::vector<double> coefficients);
    double F(double x);
    double DiffrF(double x);
    double Diffr2F(double x);

private:
    const int degree = 3;
    std::vector<double> coefficients;
};

double S(double x, double x_0, double h, std::vector<double> y, Function function);
double Si(double x, double xi, double xi_1, double yi, double yi_1, double h, Function function);
double Round(double X, double Delta);
#endif
