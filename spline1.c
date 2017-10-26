#include "spline1.h"
#include "fun.h"

// Локальный сплайн
double *gen_y4(double x_0, double h) {
  double *y = new double[MAXMSIZE];
  for (int i = 0; i < sizeM; i++, x_0 += h) {
    y[i] = Difr_F(x_0);
  }
  return y;
}

// Без производных
double *gen_y3(double x_0, double h) {
  double A[MAXMSIZE][MAXMSIZE] = {0},d[MAXMSIZE] = {0};
  gen_A3(A,h);
  gen_d3(d,x_0,h);
  return prog(A,d);
}

void gen_d3(double d[MAXMSIZE], double x_0, double h) {
  d[0] = 0;
  x_0 += h;
  for (int i = 1; i < sizeM-1; i++, x_0+=h) {
    d[i] = (F(x_0+h)-F(x_0))/h-(F(x_0)-F(x_0-h))/h;
  }
  d[sizeM-1] = 0;
}

void gen_A3(double A[MAXMSIZE][MAXMSIZE], double h) {
  A[0][0] = 1;
  A[0][1] = 0;
  A[1][0] = 4*h;
  A[1][1] = h;
  for (int i = 2; i < sizeM-2; i++) {
    A[i][i-1] = h;
    A[i][i] = 4*h;
    A[i][i+1] = h;
  }
  A[sizeM-2][sizeM-1] = 4*h;
  A[sizeM-2][sizeM-2] = h;
  A[sizeM-1][sizeM-1] = 1;
  A[sizeM-1][sizeM-2] = 0;
}

// Вторые производные на краях
double *gen_y2(double x_0, double h) {
  double A[MAXMSIZE][MAXMSIZE] = {0},d[MAXMSIZE] = {0};
  gen_A2(A,h);
  gen_d2(d,x_0,h);
  return prog(A,d);
}

void gen_d2(double d[MAXMSIZE], double x_0, double h) {
  d[0] = Difr2_F(x_0);
  x_0 += h;
  for (int i = 1; i < sizeM-1; i++, x_0+=h) {
    d[i] = (F(x_0+h)-F(x_0))/h-(F(x_0)-F(x_0-h))/h;
  }
  d[sizeM-1] = Difr2_F(x_0);
}

void gen_A2(double A[MAXMSIZE][MAXMSIZE], double h) {
  A[0][0] = 6;
  A[0][1] = 0;

  A[1][0] = 4*h;
  A[1][1] = h;
  for (int i = 2; i < sizeM-2; i++) {
    A[i][i-1] = h;
    A[i][i] = 4*h;
    A[i][i+1] = h;
  }
  A[sizeM-2][sizeM-1] = 4*h;
  A[sizeM-2][sizeM-2] = h;

  A[sizeM-1][sizeM-2] = 0;
  A[sizeM-1][sizeM-1] = 6;
}

// Первые производные на краях
double *gen_y1(double x_0, double h) {
  double A[MAXMSIZE][MAXMSIZE] = {0},d[MAXMSIZE] = {0};
  gen_A1(A,h);
  gen_d1(d,x_0,h);
  return prog(A,d);
}

void gen_d1(double d[MAXMSIZE], double x_0, double h) {
  d[0] = (F(x_0+h)-F(x_0))/h-Difr_F(x_0);
  x_0 += h;
  for (int i = 1; i < sizeM-1; i++, x_0+=h) {
    d[i] = (F(x_0+h)-F(x_0))/h-(F(x_0)-F(x_0-h))/h;
  }
  d[sizeM-1] = Difr_F(x_0)-(F(x_0)-F(x_0-h))/h;
}


void gen_A1(double A[MAXMSIZE][MAXMSIZE], double h) {
  A[0][0] = 2*h;
  A[0][1] = h;

  A[1][0] = 4*h;
  A[1][1] = h;
  for (int i = 2; i < sizeM-2; i++)
  {
    A[i][i-1] = h;
    A[i][i] = 4*h;
    A[i][i+1] = h;
  }
  A[sizeM-2][sizeM-1] = 4*h;
  A[sizeM-2][sizeM-2] = h;

  A[sizeM-1][sizeM-1] = 2*h;
  A[sizeM-1][sizeM-2] = h;
}

double alpha_gen(int n, double A[MAXMSIZE][MAXMSIZE], double alpha[MAXMSIZE]) {
  double b_n = A[n][n];
  double c_n = A[n][n+1];
  double res;
  if (n > 0)
  {
    double a_n = A[n][n-1];
    res = alpha[n] = -1*c_n/(a_n*alpha_gen(n-1, A, alpha)+b_n);
  }
  else
  {
    res = alpha[n] = -1*c_n/b_n;
  }

  return res;
}

double beta_gen(int n, double A[MAXMSIZE][MAXMSIZE], double d[MAXMSIZE], double beta[MAXMSIZE], double alpha[MAXMSIZE]) {
  double b_n = A[n][n];
  double d_n = d[n];
  double res;
  if (n > 0)
  {
    double a_n = A[n][n-1];
    double c_n = A[n][n+1];
    res = beta[n] = (d_n-a_n*beta_gen(n-1, A, d, beta, alpha))/(b_n+a_n*alpha[n-1]);
  }
  else
  {
    res = beta[n] = d_n/b_n;
  }

  return res;
}


double *prog(double A[MAXMSIZE][MAXMSIZE], double d[MAXMSIZE]) {
  double *x= new double[MAXMSIZE];
  double alpha[MAXMSIZE], beta[MAXMSIZE];

  double a_n = A[sizeM-1][sizeM-2];
  double b_n = A[sizeM-1][sizeM-1];
  double d_n = d[sizeM-1];

  alpha_gen(sizeM-1, A, alpha);
  beta_gen(sizeM-1, A, d, beta, alpha);

  x[sizeM-1] = (d_n-a_n*beta[sizeM-2])/(a_n*alpha[sizeM-2]+b_n);
  for (int i = sizeM-2; i >= 0; i--) {
    x[i] = alpha[i]*x[i+1]+beta[i];
  }
  return x;
}
