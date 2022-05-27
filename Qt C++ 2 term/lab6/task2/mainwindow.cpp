#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new HashTable<QString>();
    fmk = new FindMaxKey();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_clicked()
{
    table->Add(ui->spinBox->value(),ui->lineEdit->text());
}


void MainWindow::on_reset_clicked()
{
    if(table->Find(ui->spinBox->value() ) == nullptr)
    {
        QMessageBox::critical(this,"Info","Выбранный ключ не найден");
        return;
    }
    table->Remove(ui->spinBox->value());
}


void MainWindow::on_find_clicked()
{
    Stack<std::pair<int,QString>> *tmp = table->Find(ui->spinBox->value());
    if(tmp == nullptr)
    {
        QMessageBox::critical(this,"Info","Не найдено совпадений");
        return;
    }
    else
    {
       ui->listWidget->clear();
       int index = tmp->index;
       for(int i = index - 1; i >= 0;i--)
       {
           ui->listWidget->addItem(QString::number(tmp->array[i].first) + tmp->array[i].second);
       }
    }
}


void MainWindow::on_print_clicked()
{
    ui->listWidget->clear();
    for(int i = 0; i < table->capacity;i++)
    {
        Stack<std::pair<int,QString>> * tmp = table->Find(i);
        if(tmp != nullptr)
        {
            ui->listWidget->addItem(QString::number(i) + "-ый элемент");
            for(int j = tmp->index - 1;j >= 0;j--)
                ui->listWidget->addItem(QString::number(tmp->array[j].first) + tmp->array[j].second);
        }
    }
}


void MainWindow::on_clear_clicked()
{
    ui->listWidget->clear();
}


void MainWindow::on_random_clicked()
{
    for(int i = 0 ;i < 20;i++)
    {
        int key = rand() % 50;
        fmk->Add(key,"key" + QString::number(key));
    }
}


void MainWindow::on_Print_t2_clicked()
{
    ui->listWidget->clear();
    for(int i = 0; i < fmk->capacity;i++)
    {
        Stack<std::pair<int,QString>> * tmp = fmk->Find(i);
        if(tmp != nullptr)
        {
            ui->listWidget->addItem(QString::number(i) + "-ый элемент");
            for(int j = tmp->index - 1;j >= 0;j--)
            {
                ui->listWidget->addItem(QString::number(tmp->array[j].first)+ " " +tmp->array[j].second);
            }
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    Stack<std::pair<int,QString>> * tmp = fmk->find_max();
    if(tmp != nullptr)
    {
        for(int j = tmp->index;j >= 0;j--)
            ui->listWidget->addItem(QString::number(tmp->array[j].first) + tmp->array[j].second);
    }
}

