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
    deq->push_back(ui->pb_spBox->value());
    QMessageBox::information(this,"Info","Число " + QString::number(ui->pb_spBox->value()) + " добавлено в конец");
}


void MainWindow::on_push_front_clicked()
{
    deq->push_front(ui->pf_spBox->value());
    QMessageBox::information(this,"Info","Число " + QString::number(ui->pf_spBox->value()) + " добавлено в начало");
}


void MainWindow::on_pop_back_clicked()
{
    if(!deq->empty())
    {
        deq->pop_back();
        QMessageBox::information(this,"Info","Удалён последний элемент");
    }
}


void MainWindow::on_pop_front_clicked()
{
    if(!deq->empty())
    {
        deq->pop_front();
        QMessageBox::information(this,"Info","Удалён первый элемент");
    }
}


void MainWindow::on_back_clicked()
{
    if(!deq->empty())
        QMessageBox::information(this,"Info",QString::number(deq->back()));
    else
        QMessageBox::critical(this,"Info","Empty!");
}


void MainWindow::on_front_clicked()
{
    if(!deq->empty())
        QMessageBox::information(this,"Info",QString::number(deq->front()));
    else
        QMessageBox::critical(this,"Info","Empty!");
}


void MainWindow::on_empty_clicked()
{
    if(!deq->empty())
        QMessageBox::information(this,"Info","Not empty!");
    else
        QMessageBox::information(this,"Info","Empty!");
}


void MainWindow::on_size_clicked()
{
    QMessageBox::information(this,"Info",QString::number(deq->Size()));
}


void MainWindow::on_clear_clicked()
{
    if(deq->empty())
        QMessageBox::critical(this,"Info","Empty!");
    else
    {
        deq->clear();
        QMessageBox::information(this,"Info","Deck is empty!");
    }
}

