#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gnuplot_i.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double F(double x);

private slots:
    void on_Action_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
