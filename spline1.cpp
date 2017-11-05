#include "spline1.h"
#include "fun.h"
#include <iostream>

// Локальный сплайн
std::vector<double> gen_y4(double x_0, double h, Function function) {
    std::vector<double> y(MAXMSIZE, 0);
    for (int i = 0; i < sizeM; i++, x_0 += h) {
        y[i] = function.DiffrF(x_0);
    }
    return y;
}

// Без производных
std::vector<double> gen_y3(double x_0, double h, Function function) {
    std::vector<std::vector<double>> A = gen_A3(h);
    std::vector<double> d = gen_d3(x_0, h, function);
    return prog(A, d);
}

std::vector<double> gen_d3(double x_0, double h, Function function) {
    std::vector<double> d(MAXMSIZE, 0);
    d[0] = 0;
    x_0 += h;
    for (int i = 1; i < sizeM - 1; i++, x_0 += h) {
        d[i] = (function.F(x_0 + h) - function.F(x_0)) / h - (function.F(x_0) - function.F(x_0 - h)) / h;
    }
    d[sizeM - 1] = 0;
    return d;
}

std::vector<std::vector<double>> gen_A3(double h) {
    std::vector<std::vector<double>> A(MAXMSIZE, std::vector<double> (MAXMSIZE, 0));
    A[0][0] = 1;
    A[0][1] = 0;
    A[1][0] = 4 * h;
    A[1][1] = h;
    for (int i = 2; i < sizeM - 2; i++) {
        A[i][i - 1] = h;
        A[i][i] = 4 * h;
        A[i][i + 1] = h;
    }
    A[sizeM - 2][sizeM - 1] = 4 * h;
    A[sizeM - 2][sizeM - 2] = h;
    A[sizeM - 1][sizeM - 1] = 1;
    A[sizeM - 1][sizeM - 2] = 0;
    return A;
}

// Вторые производные на краях
std::vector<double> gen_y2(double x_0, double h, Function function) {
    std::vector<std::vector<double>> A = gen_A2(h);
    std::vector<double> d = gen_d2(x_0, h, function);

    return prog(A,d);
}

std::vector<double> gen_d2(double x_0, double h, Function function) {
    std::vector<double> d(MAXMSIZE, 0);
    d[0] = function.Diffr2F(x_0);
    x_0 += h;
    for (int i = 1; i < sizeM-1; i++, x_0+=h) {
        d[i] = (function.F(x_0 + h) - function.F(x_0)) / h - (function.F(x_0) - function.F(x_0-h)) / h;
    }
    d[sizeM - 1] = function.Diffr2F(x_0);
    return d;
}

std::vector<std::vector<double>> gen_A2(double h) {
    std::vector<std::vector<double>> A(MAXMSIZE, std::vector<double> (MAXMSIZE, 0));
    A[0][0] = 6;
    A[0][1] = 0;

    A[1][0] = 4 * h;
    A[1][1] = h;
    for (int i = 2; i < sizeM-2; i++) {
        A[i][i - 1] = h;
        A[i][i] = 4 * h;
        A[i][i + 1] = h;
    }
    A[sizeM - 2][sizeM - 1] = 4 * h;
    A[sizeM - 2][sizeM - 2] = h;

    A[sizeM - 1][sizeM - 2] = 0;
    A[sizeM - 1][sizeM - 1] = 6;
    return A;
}

// Первые производные на краях
std::vector<double> gen_y1(double x_0, double h, Function function) {
    std::vector<std::vector<double>> A = gen_A1(h);
    std::vector<double> d = gen_d1(x_0, h, function);
    return prog(A, d);
}

std::vector<double> gen_d1(double x_0, double h, Function function) {
    std::vector<double> d(MAXMSIZE, 0);
    d[0] = (function.F(x_0 + h) - function.F(x_0)) / h - function.DiffrF(x_0);
    x_0 += h;
    for (int i = 1; i < sizeM-1; i++, x_0+=h) {
        d[i] = (function.F(x_0 + h) - function.F(x_0)) / h - (function.F(x_0) - function.F(x_0 - h)) / h;
    }
    d[sizeM - 1] = function.DiffrF(x_0) - (function.F(x_0) - function.F(x_0 - h)) / h;
    return d;
}

std::vector<std::vector<double>> gen_A1(double h) {
    std::vector<std::vector<double>> A(MAXMSIZE, std::vector<double> (MAXMSIZE, 0));
    A[0][0] = 2 * h;
    A[0][1] = h;

    A[1][0] = 4 * h;
    A[1][1] = h;
    for (int i = 2; i < sizeM - 2; i++){
        A[i][i-1] = h;
        A[i][i] = 4 * h;
        A[i][i + 1] = h;
    }
    A[sizeM - 2][sizeM - 1] = 4 * h;
    A[sizeM - 2][sizeM - 2] = h;

    A[sizeM - 1][sizeM - 1] = 2 * h;
    A[sizeM - 1][sizeM - 2] = h;
    return A;
}

double alpha_gen(int n, std::vector<std::vector<double>> A, std::vector<double> &alpha) {
    double b_n = A[n][n];
    double c_n = A[n][n + 1];
    double res;
    if (n > 0){
        double a_n = A[n][n - 1];
        res = alpha[n] = -1 * c_n / (a_n * alpha_gen(n - 1, A, alpha) + b_n);
    }
    else{
        res = alpha[n] = -1 * c_n / b_n;
    }
  return res;
}

double beta_gen(int n, std::vector<std::vector<double>> A, std::vector<double> d, std::vector<double> &beta, std::vector<double> alpha) {
  double b_n = A[n][n];
  double d_n = d[n];
  double res;
  if (n > 0) {
      double a_n = A[n][n - 1];
      double c_n = A[n][n + 1];
      res = beta[n] = (d_n-a_n*beta_gen(n-1, A, d, beta, alpha))/(b_n+a_n*alpha[n-1]);
    }
    else {
      res = beta[n] = d_n / b_n;
    }
    return res;
}


std::vector<double> prog(std::vector<std::vector<double>> A, std::vector<double> d) {
    std::vector<double> x(MAXMSIZE, 0);
    std::vector<double> alpha(MAXMSIZE, 0);
    std::vector<double> beta(MAXMSIZE, 0);

    double a_n = A[sizeM - 1][sizeM - 2];
    double b_n = A[sizeM - 1][sizeM - 1];
    double d_n = d[sizeM - 1];

    alpha_gen(sizeM - 1, A, alpha);
    beta_gen(sizeM - 1, A, d, beta, alpha);

    x[sizeM - 1] = (d_n - a_n * beta[sizeM - 2])/(a_n * alpha[sizeM - 2] + b_n);
    for (int i = sizeM - 2; i >= 0; i--) {
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }
    return x;
}
