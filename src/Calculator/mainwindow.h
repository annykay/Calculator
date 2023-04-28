#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QVector>
#include <QPrinter>
extern "C" {
#include "../smart_calc.h"
};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void add_sign();
    void add_digit();
    void add_minus();
    void add_func();
    void plot();
    void on_pushButton_eq_clicked();
    void on_pushButton_ac_clicked();
};

#endif // MAINWINDOW_H
