#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deq = new Deque<int>();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_back_clicked()
{
    deq->push_back(ui->spinBox->value());
    ui->listWidget->addItem(QString::number(deq->back()));
}


void MainWindow::on_pop_back_clicked()
{
    if(deq->empty())
    {
        QMessageBox::warning(this,"Empty","Empty!");
        return;
    }
    deq->pop_back();
}


void MainWindow::on_push_front_clicked()
{
    deq->push_front(ui->spinBox->value());
    ui->listWidget->addItem(QString::number(deq->front()));
}


void MainWindow::on_pushButton_9_clicked()
{
    if(deq->empty())
    {
        QMessageBox::warning(this,"Empty","Empty!");
        return;
    }
    deq->pop_front();
}


void MainWindow::on_pushButton_4_clicked()
{
    if(deq->empty())
    {
        QMessageBox::warning(this,"Empty","True");
    }
    else
    {
        QMessageBox::warning(this,"Empty","False");
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this,"Size:",QString::number(deq->Size()));
}


void MainWindow::on_pushButton_3_clicked()
{
    deq->clear();
}


void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox::information(this,"Front",QString::number(deq->front()));
}


void MainWindow::on_pushButton_8_clicked()
{
    QMessageBox::information(this,"Back",QString::number(deq->back()));
}


void MainWindow::on_random_clicked()
{
    if(deq->Size() - 1 < ui->spinBox_2->value())
    {
        QMessageBox::information(this,"Error","i > size");
        return;
    }
    QMessageBox::information(this,"Back",QString::number(deq->randomAccess(ui->spinBox_2->value())));
}

