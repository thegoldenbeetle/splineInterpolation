#ifndef SPLINE
#define SPLINE
#define MAXMSIZE 100

#include "fun.h"
#include <vector>

class Spline {
public:
    Spline(double x_0, double h, Function function):
        x_0(x_0), h(h), function(function) {}

    std::vector<double> gen_y4();

    std::vector<double> gen_y3();
    std::vector<double> gen_d3();
    std::vector<std::vector<double>> gen_A3();

    std::vector<double> gen_y2();
    std::vector<double> gen_d2();
    std::vector<std::vector<double>> gen_A2();

    std::vector<double> gen_y1();
    std::vector<double> gen_d1();
    std::vector<std::vector<double> > gen_A1();

    // Генерациия alpha до n-го номера включительно
    double alpha_gen(int n, std::vector<std::vector<double>> A, std::vector<double> &alpha);

    // Генеряция beta до n-го номера включительно
    double beta_gen(int n, std::vector<std::vector<double> > A, std::vector<double> d,
                    std::vector<double> &beta, std::vector<double> alpha);

    // Вычисление трехполосной матрицы методом прогонки
    std::vector<double> prog(std::vector<std::vector<double>> A, std::vector<double> d);

    double S(double x, std::vector<double> y);
    double Si(double x, double xi, double xi_1, double yi, double yi_1);

    double x_0;
    double h;
    Function function;

    // Размер матрицы решений
    static const int sizeM = MAXMSIZE;
};

#endif
