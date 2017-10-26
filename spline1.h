#ifndef SPLINE
#define SPLINE
#define MAXMSIZE 100



double *gen_y4(double x_0, double h);

double *gen_y3(double x_0, double h);
void gen_d3(double d[MAXMSIZE], double x_0, double h);
void gen_A3(double A[MAXMSIZE][MAXMSIZE], double h);

double *gen_y2(double x_0, double h);
void gen_d2(double d[MAXMSIZE], double x_0, double h);
void gen_A2(double A[MAXMSIZE][MAXMSIZE], double h);

double *gen_y1(double x_0, double h);
void gen_d1(double d[MAXMSIZE], double x_0, double h);
void gen_A1(double A[MAXMSIZE][MAXMSIZE], double h);



// Генерациия alpha до n-го номера включительно
double alpha_gen(int n, double A[MAXMSIZE][MAXMSIZE], double alpha[MAXMSIZE]);

// Генеряция beta до n-го номера включительно
double beta_gen(int n, double A[MAXMSIZE][MAXMSIZE], double d[MAXMSIZE],
                double beta[MAXMSIZE], double alpha[MAXMSIZE]);

// Вычисление трехполосной матрицы методом прогонки
double *prog(double A[MAXMSIZE][MAXMSIZE], double d[MAXMSIZE]);

// Создание вектора для вычисление неизвестный констант
void gen_d(double d[MAXMSIZE], double x_0, double h);

// Создание матрицы для вычисления неизвесных констант
void gen_A(double A[MAXMSIZE][MAXMSIZE], double h);

// Размер матрицы решений
int sizeM = MAXMSIZE;
#endif
