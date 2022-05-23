#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    rect = new Rectangle;
    timer = new QTimer;
    truck = new Truck;
    ui->graphicsView->setScene(scene);
    scene->addItem(truck);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    connect(timer,SIGNAL(timeout()),truck,SLOT(move_left()));
    timer->start(10);

}


void MainWindow::on_pushButton_2_clicked()
{
    connect(timer,SIGNAL(timeout()),truck,SLOT(move_right()));
    timer->start(10);
}


void MainWindow::on_pushButton_3_clicked()
{
    if(truck->raise == true)
        truck->raise = false;
    else
        truck->raise = true;
}


