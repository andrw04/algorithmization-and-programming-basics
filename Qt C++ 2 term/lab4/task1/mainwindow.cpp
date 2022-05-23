#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <pair.cpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Pair<int, int> a(10,10);
    Pair<int, int> b(15,17);
    a.swap(b);
    QMessageBox::information(this,"", "first" + QString::number(a.first) + " second " + QString::number(a.second));
}

MainWindow::~MainWindow()
{
    delete ui;
}

