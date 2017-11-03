#ifndef FUN
#define FUN
class Function {
public:
    Function (double a, double b, double c, double d);
    double F(double x);
    double DiffrF(double x);
    double Diffr2F(double x);

    double a;
    double b;
    double c;
    double d;
};

double S(double x, double x_0, double h, double *y, Function function);
double Si(double x, double xi, double xi_1, double yi, double yi_1, double h, Function function);
double Round(double X, double Delta);
#endif
