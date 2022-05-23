#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    q = new Queue<int>();
    v = new ViewImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_clicked()
{
    q->push_back(ui->spinBox->value());
}

void MainWindow::on_pop_clicked()
{
    q->pop_front();
}

void MainWindow::on_size_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem("Size: " + QString::number(q->getSize()));
}


void MainWindow::on_front_clicked()
{
    ui->listWidget->clear();
    if(q->empty())
    {
        ui->listWidget->addItem("Empty");
    }
    else
    {
        ui->listWidget->addItem("First item: " + QString::number(q->front()));
    }
}


void MainWindow::on_back_clicked()
{
    ui->listWidget->clear();
    if(q->empty())
    {
        ui->listWidget->addItem("Empty");
    }
    else
    {
        ui->listWidget->addItem("Last item: " + QString::number(q->back()));
    }
}


void MainWindow::on_empty_clicked()
{
    ui->listWidget->clear();
    if(q->empty())
    {
        ui->listWidget->addItem("Empty");
    }
    else
    {
        ui->listWidget->addItem("Not empty");
    }
}


void MainWindow::on_load_img_clicked()
{
    //QLabel *label = new QLabel();
    QImage itm1("C:/Projects/Qt/lab5/task1/1.png");
    v->push_back(itm1);
    QImage itm2("C:/Projects/Qt/lab5/task1/2.png");
    v->push_back(itm2);
    QImage itm3("C:/Projects/Qt/lab5/task1/3.png");
    v->push_back(itm3);
    QImage itm4("C:/Projects/Qt/lab5/task1/4.png");
    v->push_back(itm4);
    ui->label_2->setPixmap(QPixmap::fromImage(v->front()));
}


void MainWindow::on_left_clicked()
{
    v->move_left();
    ui->label_2->setPixmap(QPixmap::fromImage(v->front()));
}


void MainWindow::on_right_clicked()
{
    v->move_right();
    ui->label_2->setPixmap(QPixmap::fromImage(v->front()));
}

