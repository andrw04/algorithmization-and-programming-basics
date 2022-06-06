#include "mainwindow.h"
#include "ui_mainwindow.h"

BITSET a;
BITSET b;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem(QString::fromStdString(a.toString()));
    ui->listWidget_2->addItem(QString::fromStdString(b.toString()));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked(){
    unsigned short pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Ошибка ввода", "Проверьте ввод");
         pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     }

    a.set(pos);
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(a.toString()));
}

void  MainWindow::on_pushButton_2_clicked(){
    unsigned short pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Ошибка ввода", "Проверьте ввод");
         pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     }

    b.set(pos);
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(QString::fromStdString(b.toString()));

}

void  MainWindow::on_pushButton_3_clicked(){
    unsigned short pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Ошибка ввода", "Проверьте ввод");
         pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     }

    a.reset(pos);
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(a.toString()));
}

void  MainWindow::on_pushButton_4_clicked(){
    a.flip();
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(a.toString()));
}

void  MainWindow::on_pushButton_5_clicked(){
    unsigned short pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Ошибка ввода", "Проверьте ввод");
         pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     }

    b.reset(pos);
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(QString::fromStdString(b.toString()));
}

void  MainWindow::on_pushButton_6_clicked(){
    b.flip();
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(QString::fromStdString(b.toString()));
}

void  MainWindow::on_pushButton_7_clicked(){
    BITSET temp = a | b;
    QString OR = QString::fromStdString(temp.toString());
    QMessageBox::information(this,"OR",OR);
}

void  MainWindow::on_pushButton_8_clicked(){
    unsigned short pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Ошибка ввода", "Проверьте ввод");
         pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     }

    if(a.test(pos))
        QMessageBox::information(ui->centralwidget, "TestInfo", "True");
    else
        QMessageBox::information(ui->centralwidget, "TestInfo", "False");

}

void  MainWindow::on_pushButton_9_clicked(){
    unsigned short pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Ошибка ввода", "Проверьте ввод");
         pos = QInputDialog::getInt(this,"Введите позицию","Позиция:",0,0,31);
     }

    if(b.test(pos))
        QMessageBox::information(ui->centralwidget, "TestInfo", "True");
    else
        QMessageBox::information(ui->centralwidget, "TestInfo", "False");
}


void MainWindow::on_pushButton_10_clicked()
{
    QMessageBox::information(this,"to_ullong",QString::number(a.to_ullong()));
}


void MainWindow::on_pushButton_11_clicked()
{
    QMessageBox::information(this,"to_ulong",QString::number(a.to_ulong()));
}


void MainWindow::on_pushButton_12_clicked()
{
    QMessageBox::information(this,"to_ulong",QString::number(b.to_ulong()));
}


void MainWindow::on_pushButton_13_clicked()
{
    QMessageBox::information(this,"to_ullong",QString::number(b.to_ullong()));
}


void MainWindow::on_pushButton_14_clicked()
{
   BITSET temp = ~a;
   QString temp_not = QString::fromStdString(temp.toString());
   QMessageBox::information(this,"~",temp_not);
}


void MainWindow::on_pushButton_15_clicked()
{
    BITSET temp = ~b;
    QString temp_not = QString::fromStdString(temp.toString());
    QMessageBox::information(this,"~",temp_not);
}


void MainWindow::on_pushButton_16_clicked()
{
    BITSET temp = a & b;
    QString AND = QString::fromStdString(temp.toString());
    QMessageBox::information(this,"AND",AND);
}


void MainWindow::on_pushButton_17_clicked()
{
     QString count = QString::number(a.count());
     QMessageBox::information(this,"COUNT",count);
}


void MainWindow::on_pushButton_18_clicked()
{
    QString count = QString::number(b.count());
    QMessageBox::information(this,"COUNT",count);
}

