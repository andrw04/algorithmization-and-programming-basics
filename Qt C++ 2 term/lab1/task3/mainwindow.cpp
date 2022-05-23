#include "mainwindow.h"
#include "ui_mainwindow.h"

int arrSize = 1;
int lastChange = 0;
bool birth= false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dates = new Date[arrSize];
}

MainWindow::~MainWindow()
{
    delete ui;
}

Date* addDate(Date* obj,QString day,QString month,QString year)
{
    if(arrSize == 1)
    {
        obj[0].setDate(day,month,year);
    }
    else
    {
        Date *tmp_obj = new Date[arrSize];
        for(int i = 0; i < arrSize - 1;i++)
        {
            tmp_obj[i] = obj[i];
        }
        delete[] obj;
        obj = tmp_obj;
        obj[arrSize - 1].setDate(day,month,year);
    }
    arrSize++;
    return obj;
}


void MainWindow::on_pushButton_clicked() // Добавить дату рождения
{
    QString str = ui->lineEdit->text();
    if(str.size() != 10)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    QString day = str;
    day.remove(2,8);
    if(day.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < day.size();i++)
    {
        if(day[i] > '9' || day[i] < '0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    if(day.toInt() > 31)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }

    QString month = str;
    month.remove(5,5);
    month.remove(0,3);
    if(month.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < month.size();i++)
    {
        if(month[i] > '9' || month[i] < '0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    if(month.toInt() > 12)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }

    QString year = str;
    year.remove(0,6);
    if(year.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < year.size();i++)
    {
        if(year[i] > '9' || year[i] <'0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }

    birthday.setDate(day,month,year);
    birth = true;
    /*ui->tableWidget->setRowCount(rowCount);
    QTableWidgetItem *itm = new QTableWidgetItem(birthday.returnString());
    ui->tableWidget->setItem(rowCount - 1,0,itm);
    rowCount++;
    delete itm;
*/
}


void MainWindow::on_next_clicked()
{
    if(!ui->tableWidget->currentItem())
    {
        QMessageBox::warning(this,"Ошибка","Выберите дату");
        return;
    }
    QString str = ui->tableWidget->currentItem()->text();
    for(int i = 0; i < arrSize - 1;i++)
    {
        if(str == dates[i].returnString())
        {
            QMessageBox *message = new QMessageBox;
            Date d = dates[i].NextDay();
            message->setText(d.returnString());
            message->show();
            break;
        }
    }
}


 void MainWindow::on_prev_clicked()
{
     if(!ui->tableWidget->currentItem())
     {
         QMessageBox::warning(this,"Ошибка","Выберите дату");
         return;
     }
    QString str = ui->tableWidget->currentItem()->text();
    for(int i = 0; i < arrSize - 1;i++)
    {
        if(str == dates[i].returnString())
        {
            QMessageBox *message = new QMessageBox;
            Date d = dates[i].PreviousDay();
            message->setText(d.returnString());
            message->show();
            break;
        }
    }
}


void MainWindow::on_leap_clicked()
{
    if(!ui->tableWidget->currentItem())
    {
        QMessageBox::warning(this,"Ошибка","Выберите дату");
        return;
    }
    QString str = ui->tableWidget->currentItem()->text();
    for(int i = 0; i < arrSize - 1;i++)
    {
        if(str == dates[i].returnString())
        {
            QMessageBox *message = new QMessageBox;
            if(dates[i].IsLeap())
            {
            message->setText("Високосный");
            }
            else
            {
                message->setText("Не високосный");
            }
            message->show();
            break;
        }
    }
}


void MainWindow::on_weekNumber_clicked()
{
    if(!ui->tableWidget->currentItem())
    {
        QMessageBox::warning(this,"Ошибка","Выберите дату");
        return;
    }
    QString str = ui->tableWidget->currentItem()->text();
    for(int i = 0; i < arrSize - 1;i++)
    {
        if(str == dates[i].returnString())
        {
            QMessageBox *message = new QMessageBox;
            message->setText(QString::number(dates[i].WeekNumber()));
            message->show();
            break;
        }
    }
}


void MainWindow::on_tillBirthday_clicked()
{
    if(!birth)
    {
        QMessageBox::warning(this,"Ошибка","Введите дату рождения");
        return;
    }
    if(!ui->tableWidget->currentItem())
    {
        QMessageBox::warning(this,"Ошибка","Выберите дату");
        return;
    }
    QString str = ui->tableWidget->currentItem()->text();
    for(int i = 0; i < arrSize - 1;i++)
    {
        if(str == dates[i].returnString())
        {
            QMessageBox *message = new QMessageBox;
            message->setText(QString::number(dates[i].DaysTillYourBithday(birthday)));
            message->show();
            break;
        }
    }
}


void MainWindow::on_duration_clicked()
{
    if(!ui->tableWidget->currentItem())
    {
        QMessageBox::warning(this,"Ошибка","Выберите дату");
        return;
    }
    QString str = ui->tableWidget->currentItem()->text();
    for(int i = 0; i < arrSize - 1;i++)
    {
        if(str == dates[i].returnString() && i < arrSize - 2)
        {
            QMessageBox *message = new QMessageBox;
            message->setText(QString::number(dates[i].Duration(dates[i+1])));
            message->show();
            break;
        }
    }
}


void MainWindow::on_fileOpen_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл", "C:\\","TXT File (*.txt)"));
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString str = in.readLine();
        if(str.size() != 10)
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        QString day = str;
        day.remove(2,8);
        if(day.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0; i < day.size();i++)
        {
            if(day[i] > '9' || day[i] < '0')
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        if(day.toInt() > 31)
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        QString month = str;
        month.remove(5,5);
        month.remove(0,3);
        if(month.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0; i < month.size();i++)
        {
            if(month[i] > '9' || month[i] < '0')
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        if(month.toInt() > 12)
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        QString year = str;
        year.remove(0,6);
        if(year.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0; i < year.size();i++)
        {
            if(year[i] > '9' || year[i] <'0')
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        dates = addDate(dates,day,month,year);
    }
    file.close();
}


void MainWindow::on_Save_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,"Сохранить список дат", "C:\\","TXT File (*.txt)"));
    if (!file.open(QIODevice::WriteOnly|QIODevice::Append)) {
        qWarning("Cannot open file for writing");
    }
    file.seek(lastChange * 11);
    QTextStream out(&file);
    for(int i = lastChange; i < arrSize - 1;i++)
    {
        out << dates[i].returnString() << "\n";
    }
    file.close();
    lastChange = 0;
}


void MainWindow::on_show_clicked()
{
    ui->tableWidget->setRowCount(arrSize - 1);
    for(int i = 0; i < arrSize - 1;i++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(dates[i].returnString());
        ui->tableWidget->setItem(i,0,itm);
    }
}


void MainWindow::on_add_clicked()
{
    QString dat = QInputDialog::getText(this,"Дату(дд.мм.гггг)","Дата:",QLineEdit::Normal);
    if(dat.size() != 10)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    QString day = dat;
    day.remove(2,8);
    if(day.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < day.size();i++)
    {
        if(day[i] > '9' || day[i] < '0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    if(day.toInt() > 31)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    QString month = dat;
    month.remove(5,5);
    month.remove(0,3);
    if(month.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < month.size();i++)
    {
        if(month[i] > '9' || month[i] < '0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    if(month.toInt() > 12)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    QString year = dat;
    year.remove(0,6);
    if(year.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < year.size();i++)
    {
        if(year[i] > '9' || year[i] <'0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    dates = addDate(dates,day,month,year);
}


void MainWindow::on_add_2_clicked() // изменить элемент
{
    if(!ui->tableWidget->currentItem())
    {
        QMessageBox::warning(this,"Ошибка","Выберите дату");
        return;
    }
    QString str = ui->tableWidget->currentItem()->text();
    QString dat = QInputDialog::getText(this,"Дату(дд.мм.гггг)","Дата:",QLineEdit::Normal);
    if(dat.size() != 10)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    QString day = dat;
    day.remove(2,8);
    if(day.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < day.size();i++)
    {
        if(day[i] > '9' || day[i] < '0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    if(day.toInt() > 31)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    QString month = dat;
    month.remove(5,5);
    month.remove(0,3);
    if(month.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < month.size();i++)
    {
        if(month[i] > '9' || month[i] < '0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    if(month.toInt() > 12)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    QString year = dat;
    year.remove(0,6);
    if(year.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0; i < year.size();i++)
    {
        if(year[i] > '9' || year[i] <'0')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    for(int i = 0; i < arrSize - 1; i++)
    {
        if(str == dates[i].returnString())
        {
            dates[i].setDate(day,month,year);
                lastChange = i;
        }
    }
}

