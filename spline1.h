#ifndef SPLINE
#define SPLINE
#define MAXMSIZE 100

#include "fun.h"
#include <vector>

std::vector<double> gen_y4(double x_0, double h, Function function);

std::vector<double> gen_y3(double x_0, double h, Function function);
std::vector<double> gen_d3(double x_0, double h, Function function);
std::vector<std::vector<double>> gen_A3(double h);

std::vector<double> gen_y2(double x_0, double h, Function function);
std::vector<double> gen_d2(double x_0, double h, Function function);
std::vector<std::vector<double>> gen_A2(double h);

std::vector<double> gen_y1(double x_0, double h, Function function);
std::vector<double> gen_d1(double x_0, double h, Function function);
std::vector<std::vector<double> > gen_A1(double h);



// Генерациия alpha до n-го номера включительно
double alpha_gen(int n, std::vector<std::vector<double>> A/*, std::vector<double> &alpha*/);

// Генеряция beta до n-го номера включительно
double beta_gen(int n, std::vector<std::vector<double> > A, std::vector<double> d,
                std::vector<double> &beta, std::vector<double> alpha);

// Вычисление трехполосной матрицы методом прогонки
std::vector<double> prog(std::vector<std::vector<double>> A, std::vector<double> d);

// Размер матрицы решений
static int sizeM = MAXMSIZE;
#endif
