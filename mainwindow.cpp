#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include "gnuplot_i.h"
#include "gnuplot_i.c"
#include <stdio.h>
#include "fun.h"
#include "fun.c"
#include "spline1.h"
#include "spline1.c"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::F(double x, double a,  double b,  double c, double d)
{
    return a*(x*x*x) + b*(x*x) + c*x + d;
}


void MainWindow::on_buildGraphics_clicked()
{
    double x0 = (ui->x_0Edit->text()).toFloat();
    double xn = (ui->x_nEdit->text()).toFloat();
    double xh = (ui->stepXEdit->text()).toFloat();
    double h = (ui->stepInterpolationEdit->text()).toFloat();
    double a = (ui->x3Edit->text()).toFloat();
    double b = (ui->x2Edit->text()).toFloat();
    double c = (ui->xEdit->text()).toFloat();
    double d = (ui->x0Edit->text()).toFloat();
    Function function = Function(a, b, c, d);
    std::ofstream ofs("data.log");
    std::ofstream ofs1("data1.log");
    std::ofstream ofs2("data2.log");
    std::ofstream ofs3("data3.log");

    sizeM = (int)((xn-x0)/h+2);
    double *y1 = gen_y1(x0, h, function), *y2 = gen_y2(x0, h, function), *y3 = gen_y3(x0, h, function);

    double x = x0;
    double  Max1=-100000, Max2=-100000, Max3=-100000;
    double x1,x2,x3;
    while (x <= xn)
    {
        double fx = function.F(x);
        ofs << x << " " << fx << std::endl;
        if (fx - S(x, x0, h, y1, function) > Max1) {
            Max1 = fx - S(x, x0, h, y1, function);
            x1 = x;
        }
        ofs1 << x << " " << S(x, x0, h, y1, function) << std::endl;
        if (fx - S(x, x0,h,y2, function) > Max2) {
            Max2 = fx - S(x, x0, h, y2, function);
            x2 = x;
        }
        ofs2 << x << " " << S(x, x0, h, y2, function) << std::endl;
        if (fx - S(x, x0,h,y3, function) > Max3) {
            Max3 = fx - S(x, x0,h,y3, function);
            x3 = x;
        }
        ofs3 << x << " " << S(x, x0, h, y3, function) << std::endl;
        x = x + xh;
    }
    std::cout << function.Diffr2F(x - xh) * h << "\n\n";
    std::cout << Max1 << " " << x1 << "\n" << Max2 << " " << x2 << "\n" << Max3 << " " << x3 << "\n\n";
    ofs.close();
    ofs1.close();
    ofs2.close();
    ofs3.close();
    gnuplot_ctrl *g;
    g = gnuplot_init();
    gnuplot_cmd(g, "set terminal png size 521, 361");
    gnuplot_cmd(g, "set output 'graph.png'");
    gnuplot_cmd(g, "set grid xtics ytics mxtics mytics");
    gnuplot_cmd(g, "set xlabel 'x'");
    gnuplot_cmd(g, "set ylabel 'y'");
    gnuplot_cmd(g, "plot 'data.log' with lines ti 'F(x)', 'data1.log' with lines ti '1 способ', 'data2.log' with lines ti '2 способ', 'data3.log' with lines ti '3 способ'");
    gnuplot_close(g);
    QPixmap myPixmap( "graph.png" );
    ui->graphics->setPixmap(myPixmap);
}
