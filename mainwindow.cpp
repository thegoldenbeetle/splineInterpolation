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

void MainWindow::on_Action_clicked()
{
    double x0, xn, xh, h, x;
    QString str = ui->lineEdit->text();
    x0 = str.toFloat();
    str = ui->lineEdit_2->text();
    xn = str.toFloat();
    str = ui->lineEdit_3->text();
    xh = str.toFloat();
    str = ui->lineEdit_4->text();
    h = str.toFloat();
    std::ofstream ofs("data.log");
    std::ofstream ofs1("data1.log");
    std::ofstream ofs2("data2.log");
    std::ofstream ofs3("data3.log");

    sizeM = (int)((xn-x0)/h+2);
    double *y1 = gen_y1(x0, h), *y2 = gen_y2(x0, h), *y3 = gen_y3(x0, h);

    x = x0;
    double  Max1=-100000,Max2=-100000,Max3=-100000;
    double x1,x2,x3;
    while (x <= xn)
    {
        ofs << x << " " << F(x) << std::endl;
        if (F(x)-S(x, x0,h,y1) > Max1) {
            Max1 = F(x)-S(x, x0,h,y1);
            x1 = x;
        }
        ofs1 << x << " " << S(x, x0, h, y1) << std::endl;
        if (F(x)-S(x, x0,h,y2) > Max2) {
            Max2 = F(x)-S(x, x0, h, y2);
            x2 = x;
        }
        ofs2 << x << " " << S(x, x0, h, y2) << std::endl;
        if (F(x)-S(x, x0,h,y3) > Max3) {
            Max3 = F(x)-S(x, x0,h,y3);
            x3 = x;
        }
        ofs3 << x << " " << S(x, x0, h, y3) << std::endl;
        x = x + xh;
    }
    std::cout << Difr2_F(x-xh)*h << "\n\n";
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
    ui->graphic->setPixmap(myPixmap);
}

double MainWindow::F(double x)
{
    return x*x*x+2*x*x+x+3;
}

