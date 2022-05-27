#include "mainwindow.h"
#include "ui_mainwindow.h"
int count = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = new BinaryTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_show_clicked()
{
    if(count == 0)
    {
        QMessageBox::critical(this,"Info","В дереве нет вершин!");
        return;
    }
    ui->treeWidget->clear();
    tree->print_tree(ui->treeWidget);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(count == 0)
    {
        QMessageBox::critical(this,"Info","В дереве нет вершин!");
        return;
    }
    QString str = QString::fromStdString(tree->preorder());
    QMessageBox::information(this,"Info",str);
}


void MainWindow::on_pushButton_3_clicked()
{
    if(count == 0)
    {
        QMessageBox::critical(this,"Info","В дереве нет вершин!");
        return;
    }
    QString str = QString::fromStdString(tree->postorder());
    QMessageBox::information(this,"Info",str);
}


void MainWindow::on_pushButton_4_clicked()
{
    if(count == 0)
    {
        QMessageBox::critical(this,"Info","В дереве нет вершин!");
        return;
    }
    QString str = QString::fromStdString(tree->increase());
    QMessageBox::information(this,"Info",str);
}


void MainWindow::on_pushButton_clicked()
{
    tree->add_node(ui->lineEdit->text().toStdString(),ui->spinBox->value());
    count++;
}


void MainWindow::on_from_array_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount();i++)
    {
        if(ui->tableWidget->item(i,0) == 0 || ui->tableWidget->item(i,1) == 0)
            continue;
        tree->add_node(ui->tableWidget->item(i,1)->text().toStdString(),ui->tableWidget->item(i,0)->text().toInt());
        count++;
    }
}


void MainWindow::on_reset_clicked()
{
    if(QString::fromStdString(tree->print(ui->spinBox_3->value())) == "Key is not found")
    {
        QMessageBox::critical(this,"Error","Key is not found");
        return;
    }
    tree->remove(ui->spinBox_3->value());
    count--;
}


void MainWindow::on_find_clicked()
{
    QMessageBox::information(this,"Find node",QString::fromStdString(tree->print(ui->spinBox_2->value())));
}


void MainWindow::on_individual_task_clicked()
{
    if(QString::fromStdString(tree->print(ui->spinBox_3->value())) == "Key is not found")
    {
        QMessageBox::critical(this,"Error","Key is not found");
        return;
    }
    QMessageBox::information(this,"Info",QString::fromStdString(tree->individual_task()));
}

