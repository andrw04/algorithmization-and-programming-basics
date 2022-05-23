#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = new stack();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int StrNumber = 1;
    int Letter = 1;
    int Counter1 = 0; // скобка вида {
    int Counter2 = 0; // скобка вида (
    int Counter3 = 0; // скобка вида [
    QString str = ui->textEdit->toPlainText();
    for(int i = 0; i < str.size();i++)
    {
        if(str[i] == '\n')
        {
            StrNumber++;
            Letter = 1;
        }
        if(str[i] == '{')
        {
            Counter1++;
            s->push('{');
        }
        else if(str[i] == '(')
        {
            Counter2++;
            s->push('(');
        }
        else if(str[i] == '[')
        {
            Counter3++;
            s->push('(');
        }
        if(str[i] == '}')
        {
            Counter1--;
        }
        else if(str[i] == ')')
        {
            Counter2--;
        }
        else if(str[i] == ']')
        {
            Counter3--;
        }
        if(Counter1 < 0)
        {
            QMessageBox::warning(this,"Warning","Не хватает открывающей '{' для '}', расположенной в  " + QString::number(StrNumber) + "-й строке, " +
        QString::number(Letter) + "-м столбце!");
            return;
        }
        else if(Counter2 < 0)
        {
            QMessageBox::warning(this,"Warning","Не хватает открывающей '(' для ')', расположенной в  " + QString::number(StrNumber) + "-й строке, " +
        QString::number(Letter) + "-м столбце!");
            return;
        }
        else if(Counter3 < 0)
        {
            QMessageBox::warning(this,"Warning","Не хватает открывающей '[' для ']', расположенной в  " + QString::number(StrNumber) + "-й строке, " +
        QString::number(Letter) + "-м столбце!");
            return;
        }
        Letter++;
    }
    StrNumber = 1;
    Letter = 0;
    for(int i = 0; i < str.size();i++)
    {
        if(str[i] == '\n')
        {
            StrNumber++;
            Letter = 0;
        }
        if(Counter1 > 0 && str[i] == '{')
        {
            Counter1--;
            if(Counter1 == 0)
            {
                QMessageBox::warning(this,"Warning","Не хватает закрывающей '}' для '{', расположенной в  " + QString::number(StrNumber) + "-й строке, " +
        QString::number(Letter) + "-м столбце!");
            return;
            }
        }
        else if(Counter2 > 0 && str[i] == '(')
        {
            Counter2--;
            if(Counter2 == 0)
            {
               QMessageBox::warning(this,"Warning","Не хватает закрывающей ')' для '(', расположенной в  " + QString::number(StrNumber) + "-й строке, " +
        QString::number(Letter) + "-м столбце!");
               return;
            }
        }
        else if(Counter3 > 0 && str[i] == '[')
        {
            Counter3--;
            if(Counter3 == 0)
            {
                QMessageBox::warning(this,"Warning","Не хватает закрывающей ']' для '[', расположенной в  " + QString::number(StrNumber) + "-й строке, " +
        QString::number(Letter) + "-м столбце!");
                return;
            }
        }
        Letter++;
    }
    StrNumber = 1;
    Letter = 1;
    for(int i = 0; i < str.size();i++)
    {
        if(str[i] == '\n')
        {
            StrNumber++;
            Letter = 1;
        }
        if(str[i] == '{')
        {
            s->push('{');
        }
        else if(str[i] == '(')
        {
            s->push('(');
        }
        else if(str[i] == '[')
        {
            s->push('[');
        }
        if(str[i] == '}')
        {
            if(s->pop() != '{')
            {
                QMessageBox::warning(this,"Warning","Несоответствующая скобка в " + QString::number(StrNumber) + "-й строке");
                return;
            }
        }
        else if(str[i] == ')')
        {
            if(s->pop() != '(')
            {
                QMessageBox::warning(this,"Warning","Несоответствующая скобка в " +QString::number(StrNumber) + "-й строке");
                return;
            }
        }
        else if(str[i] == ']')
        {
            if(s->pop() != '[')
            {
                QMessageBox::warning(this,"Warning","Несоответствующая скобка в " + QString::number(StrNumber) + "-й строке");
                return;
            }
        }
        Letter++;
    }
    if(Counter1== 0 && Counter2 == 0 && Counter3 == 0)
    {
        QMessageBox::information(this,"Information","Success!");
        return;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    QFile file(QFileDialog::getOpenFileName(this,"Сохранить список читателей", "C:\\","TXT File (*.txt)"));
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Cannot open file for reading");
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        ui->textEdit->append(in.readLine());
    }
    file.close();
}
