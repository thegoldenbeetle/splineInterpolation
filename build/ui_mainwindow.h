/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *graphics;
    QPushButton *buildGraphics;
    QLineEdit *x_0Edit;
    QLineEdit *x_nEdit;
    QLineEdit *stepXEdit;
    QLineEdit *stepInterpolationEdit;
    QLabel *x0Label;
    QLabel *xnLabel;
    QLabel *stepXLabel;
    QLabel *stepInterpolationLabel;
    QLabel *polynomialLabel;
    QLineEdit *x3Edit;
    QLabel *x3Label;
    QLineEdit *x2Edit;
    QLabel *x2Label;
    QLineEdit *x0Edit;
    QLineEdit *xEdit;
    QLabel *xLabel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(781, 474);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphics = new QLabel(centralWidget);
        graphics->setObjectName(QStringLiteral("graphics"));
        graphics->setGeometry(QRect(230, 80, 521, 361));
        buildGraphics = new QPushButton(centralWidget);
        buildGraphics->setObjectName(QStringLiteral("buildGraphics"));
        buildGraphics->setGeometry(QRect(20, 220, 191, 51));
        QFont font;
        font.setPointSize(10);
        buildGraphics->setFont(font);
        x_0Edit = new QLineEdit(centralWidget);
        x_0Edit->setObjectName(QStringLiteral("x_0Edit"));
        x_0Edit->setGeometry(QRect(60, 20, 61, 20));
        QFont font1;
        font1.setPointSize(12);
        x_0Edit->setFont(font1);
        x_nEdit = new QLineEdit(centralWidget);
        x_nEdit->setObjectName(QStringLiteral("x_nEdit"));
        x_nEdit->setGeometry(QRect(60, 50, 61, 20));
        x_nEdit->setFont(font1);
        stepXEdit = new QLineEdit(centralWidget);
        stepXEdit->setObjectName(QStringLiteral("stepXEdit"));
        stepXEdit->setGeometry(QRect(30, 110, 101, 21));
        stepXEdit->setFont(font1);
        stepInterpolationEdit = new QLineEdit(centralWidget);
        stepInterpolationEdit->setObjectName(QStringLiteral("stepInterpolationEdit"));
        stepInterpolationEdit->setGeometry(QRect(30, 170, 113, 20));
        stepInterpolationEdit->setFont(font1);
        x0Label = new QLabel(centralWidget);
        x0Label->setObjectName(QStringLiteral("x0Label"));
        x0Label->setGeometry(QRect(30, 20, 31, 21));
        x0Label->setFont(font1);
        xnLabel = new QLabel(centralWidget);
        xnLabel->setObjectName(QStringLiteral("xnLabel"));
        xnLabel->setGeometry(QRect(30, 50, 21, 16));
        xnLabel->setFont(font1);
        stepXLabel = new QLabel(centralWidget);
        stepXLabel->setObjectName(QStringLiteral("stepXLabel"));
        stepXLabel->setGeometry(QRect(30, 90, 111, 16));
        stepXLabel->setFont(font);
        stepInterpolationLabel = new QLabel(centralWidget);
        stepInterpolationLabel->setObjectName(QStringLiteral("stepInterpolationLabel"));
        stepInterpolationLabel->setGeometry(QRect(30, 150, 141, 16));
        stepInterpolationLabel->setFont(font);
        polynomialLabel = new QLabel(centralWidget);
        polynomialLabel->setObjectName(QStringLiteral("polynomialLabel"));
        polynomialLabel->setEnabled(true);
        polynomialLabel->setGeometry(QRect(170, 20, 71, 31));
        polynomialLabel->setFont(font);
        polynomialLabel->setScaledContents(false);
        x3Edit = new QLineEdit(centralWidget);
        x3Edit->setObjectName(QStringLiteral("x3Edit"));
        x3Edit->setGeometry(QRect(250, 20, 31, 23));
        x3Label = new QLabel(centralWidget);
        x3Label->setObjectName(QStringLiteral("x3Label"));
        x3Label->setGeometry(QRect(280, 20, 51, 20));
        x2Edit = new QLineEdit(centralWidget);
        x2Edit->setObjectName(QStringLiteral("x2Edit"));
        x2Edit->setGeometry(QRect(330, 20, 31, 23));
        x2Label = new QLabel(centralWidget);
        x2Label->setObjectName(QStringLiteral("x2Label"));
        x2Label->setGeometry(QRect(360, 20, 41, 20));
        x0Edit = new QLineEdit(centralWidget);
        x0Edit->setObjectName(QStringLiteral("x0Edit"));
        x0Edit->setGeometry(QRect(470, 20, 31, 23));
        xEdit = new QLineEdit(centralWidget);
        xEdit->setObjectName(QStringLiteral("xEdit"));
        xEdit->setGeometry(QRect(410, 20, 31, 23));
        xLabel = new QLabel(centralWidget);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setGeometry(QRect(440, 20, 31, 20));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        graphics->setText(QString());
        buildGraphics->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272\320\270", Q_NULLPTR));
        x_0Edit->setText(QApplication::translate("MainWindow", "-3", Q_NULLPTR));
        x_nEdit->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        stepXEdit->setText(QApplication::translate("MainWindow", "0.2", Q_NULLPTR));
        stepInterpolationEdit->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        x0Label->setText(QApplication::translate("MainWindow", "x0", Q_NULLPTR));
        xnLabel->setText(QApplication::translate("MainWindow", "xn", Q_NULLPTR));
        stepXLabel->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 x", Q_NULLPTR));
        stepInterpolationLabel->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263 \320\270\320\275\321\202\320\265\321\200\320\277\320\276\320\273\321\217\321\206\320\270\320\270", Q_NULLPTR));
        polynomialLabel->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\270\320\275\320\276\320\274:", Q_NULLPTR));
        x3Label->setText(QApplication::translate("MainWindow", " x^3 +", Q_NULLPTR));
        x2Label->setText(QApplication::translate("MainWindow", "x^2 +", Q_NULLPTR));
        xLabel->setText(QApplication::translate("MainWindow", "x +", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
