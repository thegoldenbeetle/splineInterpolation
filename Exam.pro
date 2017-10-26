#-------------------------------------------------
#
# Project created by QtCreator 2017-01-02T18:59:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Exam
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gnuplot_i.c \
    spline1.c \
    fun.c

HEADERS  += mainwindow.h \
    gnuplot_i.h \
    spline1.h \
    fun.h

FORMS    += mainwindow.ui
