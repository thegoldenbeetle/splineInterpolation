#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include "gnuplot_i.h"
#include "gnuplot_i.c"
#include <stdio.h>
#include "fun.h"
#include "spline1.h"

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

void MainWindow::on_buildGraphics_clicked()
{
    double x0 = (ui->x_0Edit->text()).toFloat();
    double xn = (ui->x_nEdit->text()).toFloat();
    double xh = (ui->stepXEdit->text()).toFloat();
    double h = (ui->stepInterpolationEdit->text()).toFloat();
    std::vector<double> coefficients (4, 0);
    coefficients[0] = (ui->x3Edit->text()).toFloat();
    coefficients[1] = (ui->x2Edit->text()).toFloat();
    coefficients[2] = (ui->xEdit->text()).toFloat();
    coefficients[3] = (ui->x0Edit->text()).toFloat();
    Function function (coefficients);
    std::ofstream ofs("data.log");
    std::ofstream ofs1("data1.log");
    std::ofstream ofs2("data2.log");
    std::ofstream ofs3("data3.log");

    sizeM = (int) ((xn - x0) / h + 2);
    std::vector<double> y1 = gen_y1(x0, h, function);
    std::vector<double> y2 = gen_y2(x0, h, function);
    std::vector<double> y3 = gen_y3(x0, h, function);

    double x = x0;
    double  Max1 = -100000, Max2 = -100000, Max3 = -100000;
    while (x <= xn)
    {
        double fx = function.F(x);
        ofs << x << " " << fx << std::endl;

        if (fx - S(x, x0, h, y1, function) > Max1) {
            Max1 = fx - S(x, x0, h, y1, function);
        }
        ofs1 << x << " " << S(x, x0, h, y1, function) << std::endl;

        if (fx - S(x, x0, h, y2, function) > Max2) {
            Max2 = fx - S(x, x0, h, y2, function);
        }
        ofs2 << x << " " << S(x, x0, h, y2, function) << std::endl;

        if (fx - S(x, x0, h, y3, function) > Max3) {
            Max3 = fx - S(x, x0, h, y3, function);
        }
        ofs3 << x << " " << S(x, x0, h, y3, function) << std::endl;
        x = x + xh;
    }
//    std::cout << function.Diffr2F(x - xh) * h << "\n\n";
//    std::cout << Max1 << " " << x1 << "\n" << Max2 << " " << x2 << "\n" << Max3 << " " << x3 << "\n\n";
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
