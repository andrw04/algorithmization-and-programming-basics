#include "mainwindow.h"
#include "ui_mainwindow.h"
int map_count = 0;
int set_count = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    unordered_map = new UNORDERED_MAP<int,std::string>();
    map = new MAP<int,std::string>();
    set = new SET<int>();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Contains_clicked()
{
    int index = QInputDialog::getInt(this,"Key","Write Key:",0,0,100);
    if(unordered_map->Contains(index) == 1)
    {
        QMessageBox::information(this,"Contains","True");
    }
    else
    {
        QMessageBox::critical(this,"Contains","False");
    }
}


void MainWindow::on_ChangeValue_clicked()
{
    int index = QInputDialog::getInt(this,"Key","Write Key:",0,0,100);
    QString newValue = QInputDialog::getText(this,"ChangeValue","New value:",QLineEdit::Normal);
    unordered_map->ChangeValue(index,newValue.toStdString());
}


void MainWindow::on_GetValue_clicked()
{
    int index = QInputDialog::getInt(this,"Key","Write Key:",0,0,100);
    QMessageBox::information(this,"Value",QString::fromStdString(unordered_map->Find(index)));
}


void MainWindow::on_Insert_clicked()
{
    unordered_map->Insert(ui->insert_key->value(),ui->insert_value->text().toStdString());
}


void MainWindow::on_Erase_clicked()
{
    int index = QInputDialog::getInt(this,"Key","Write Key:",0,0,100);
    unordered_map->Erase(index);
}


void MainWindow::on_Clear_clicked()
{
    unordered_map->Clear();
}


void MainWindow::on_Show_clicked()
{
    ui->unordered_map_view->clear();
    int index = 0;
    for(int i = 0; i < unordered_map->GetSize();i++)
    {
        std::forward_list<std::pair<int,std::string>> tmp = unordered_map->ReturnList(i);
        for(const std::pair<int,std::string> &t : tmp)
        {
            QTableWidgetItem *itm1 = new QTableWidgetItem(QString::number(t.first));
            QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(t.second));
            ui->unordered_map_view->setItem(index,0,itm1);
            ui->unordered_map_view->setItem(index,1,itm2);
            index++;
        }
    }
}


void MainWindow::on_Show_map_clicked()
{
    ui->map_view->clear();
    if(map_count == 0)
    {
        QMessageBox::critical(this,"Info","В дереве нет вершин!");
        return;
    }
    ui->map_view->clear();
    map->print_tree(ui->map_view);
}


void MainWindow::on_Insert_map_clicked()
{
    map_count++;
    map->InsertNode(ui->map_key->value(),ui->map_value->text().toStdString());
}


void MainWindow::on_Insert_set_clicked()
{
    set_count++;
    set->InsertNode(ui->insert_set_key->value());
}


void MainWindow::on_show_set_clicked()
{
    ui->set_view->clear();
    if(set_count == 0)
    {
        QMessageBox::critical(this,"Info","В дереве нет вершин!");
        return;
    }
    ui->set_view->clear();
    set->print_tree(ui->set_view);
}


void MainWindow::on_pushButton_clicked()
{
    int index = QInputDialog::getInt(this,"Key","Write Key:",0,0,100);
    if(map->cont(index))
    {
        QMessageBox::critical(this,"Info","В дереве нет вершины с таким индексом!");
        return;
    }
    map->Erase(index);
    map_count--;
}


void MainWindow::on_delete_set_clicked()
{
    int index = QInputDialog::getInt(this,"Key","Write Key:",0,0,100);
    if(set->cont(index))
    {
        QMessageBox::critical(this,"Info","В дереве нет вершины с таким индексом!");
        return;
    }
    set->Erase(index);
    set_count--;
}


void MainWindow::on_pushButton_2_clicked()
{
    int index = QInputDialog::getInt(this,"Key","Write Key:",0,0,100);
    if(map->cont(index))
    {
        QMessageBox::critical(this,"Info","В дереве нет вершины с таким индексом!");
        return;
    }
    QString newValue = QInputDialog::getText(this,"ChangeValue","New value:",QLineEdit::Normal);
    map->Change(index,newValue.toStdString());
}

