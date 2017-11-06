#ifndef FUN
#define FUN
#include <vector>

class Function {
public:
    Function (std::vector<double> coefficients);
    double F(double x);
    double DiffrF(double x);
    double Diffr2F(double x);

//private:
    const int degree = 3;
    std::vector<double> coefficients;
};
#endif
