#include "mainwindow.h"
#include "ui_mainwindow.h"


int flightCount = 0;
int arraySize = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quicksort(Schedule* arr,int first,int last)
{
    int f = first;
    int l = last;
    int middle = arr[f + l / 2].minuts;
    do
    {
        while(arr[f].minuts < middle)
            f++;
        while(arr[l].minuts > middle)
            l--;
        if(f <= l)
        {
            QString tmp = arr[f].flightNumber;
            arr[f].flightNumber = arr[l].flightNumber;
            arr[l].flightNumber = tmp;
            tmp = arr[f].planeType;
            arr[f].planeType = arr[l].planeType;
            arr[l].planeType = tmp;
            tmp = arr[f].destination;
            arr[f].destination = arr[l].destination;
            arr[l].destination = tmp;
            tmp = arr[f].time;
            arr[f].time = arr[l].time;
            arr[l].time = tmp;
            int temp = arr[f].minuts;
            arr[f].minuts = arr[l].minuts;
            arr[l].minuts = temp;
            f++;
            l--;
        }
    }while(f < l);
    if(first < l)
        quicksort(arr,first,l);
    if(f < last)
        quicksort(arr,f,last);

}

Schedule* MainWindow::addFlight(Schedule *Obj,QString flightNumber, QString planeType, QString destination, QString time) //добавить элемент
{
    if (arraySize == 0) {
        Obj = new Schedule[arraySize + 1];
        Head = Obj;
        Obj[arraySize].next = 1;
        Obj[arraySize].prev = -1;
    }
    else {
        Schedule *temp_Obj = new Schedule[arraySize + 1];
        for (int i = 0; i < arraySize; i++) {
            temp_Obj[i] = Obj[i];
            temp_Obj[i].next = i + 1;
            temp_Obj[i].prev = i - 1;
        }
        delete[] Obj;
        Obj = temp_Obj;
    }
    Obj[arraySize].flightNumber = flightNumber;
    Obj[arraySize].planeType = planeType;
    Obj[arraySize].destination = destination;
    Obj[arraySize].time = time;
    arraySize++;
    return Obj;
}


Schedule* MainWindow::delFlight(Schedule *Obj,int index)
{
    int j = 0;
    Schedule* temp_Obj = new Schedule[arraySize - 1];
    for (int i = 0; i < arraySize; i++)
    {
        if (i != index){
            temp_Obj[j] = Obj[i];
            temp_Obj[j].next = j + 1;
            temp_Obj[j].prev = j - 1;
            j++;
        }
    }
    arraySize--;
    delete[] Obj;
    Obj = temp_Obj;
    return Obj;
}




void MainWindow::on_pushButton_6_clicked() // добавить элемент
{
    QString flightnumber = ui->flightNumber->text();
    if(flightnumber.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < flightnumber.size();i++)
    {
        if(!flightnumber[i].isDigit() && flightnumber[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString planetype = ui->planeType->text();
    if(planetype.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < planetype.size();i++)
    {
        if(!planetype[i].isLetter())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString destination = ui->destination->text();
    if(destination.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < destination.size();i++)
    {
        if(!destination[i].isLetter() && destination[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString time = ui->time->text();
    if(time.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < time.size();i++)
    {
        if(!time[i].isDigit() && time[i] != ':')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    arr = addFlight(arr,flightnumber,planetype,destination,time);
    ui->listWidget->clear();
    int current = 0;
    for(int i = 0; i < arraySize;i++)
    {
        ui->listWidget->addItem(arr[i].returnString());
        current = arr[current].next;
    }
}


void MainWindow::on_pushButton_7_clicked() // удалить
{
    if(arraySize <= 0)
    {
        QMessageBox::warning(this,"Ошибка","Массив пуст!");
        return;
    }
    arr = delFlight(arr,ui->listWidget->currentRow());
    ui->listWidget->clear();
    Schedule* current = &arr[0];
    for(int i = 0; i < arraySize;i++)
    {
        ui->listWidget->addItem(current->returnString());
        current = &arr[current->next];
    }
}


void MainWindow::on_inform_2_clicked() // подсказка
{
    QMessageBox::information(this,"Info","Фильтр1 - выводит всю информацию о самолетах, отправляющихся в заданный\
пункт назначения.\n Фильтр2 - выводит всю информацию о самолетах с указанным временем вылета; в случае отмены полетов в заданном направлении позволяет удалить из списка соответствующие рейсы, в случае открытия нового направления ‒ добавить");
}


void MainWindow::on_pushButton_5_clicked() // открыть файл
{
    QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл", "C:\\","TXT File (*.txt)"));
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Cannot open file for reading");
        }
        QTextStream in(&file);
        while(!in.atEnd()){
            QString flightnumber = in.readLine();
            if(flightnumber.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < flightnumber.size();i++)
            {
                if(!flightnumber[i].isDigit() && flightnumber[i] != ' ')
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            QString planetype = in.readLine();
            if(planetype.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < planetype.size();i++)
            {
                if(!planetype[i].isLetter())
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            QString destination = in.readLine();
            if(destination.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < destination.size();i++)
            {
                if(!destination[i].isLetter() && destination[i] != ' ')
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            QString time = in.readLine();
            if(time.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < time.size();i++)
            {
                if(!time[i].isDigit() && time[i] != ':')
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            arr = addFlight(arr,flightnumber,planetype,destination,time);
        }
        ui->listWidget->clear();
        Schedule* current = &arr[0];
        for(int i = 0; i < arraySize;i++)
        {
            ui->listWidget->addItem(current->returnString());
            current = &arr[current->next];
        }
}


void MainWindow::on_pushButton_8_clicked() // сохранить
{
    QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл","C:\\","TXT File (*.txt)"));
        if(!file.open(QIODevice::WriteOnly))
        {
            qWarning("Cannot open file for writing");
        }
        QTextStream out(&file);
        Schedule* current = &arr[0];
        for(int i = 0; i < arraySize;i++)
        {
            out << current->flightNumber << '\n' << current->planeType << '\n' << current->destination << '\n' << current->time << '\n';
            current = &arr[current->next];
        }
}


void MainWindow::on_change_2_clicked() // изменить
{
    int index = ui->listWidget->currentRow();
    QString flightnumber = QInputDialog::getText(this,"Введите номер рейса","Номер рейса");
    if(flightnumber.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < flightnumber.size();i++)
    {
        if(!flightnumber[i].isDigit() && flightnumber[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString planetype = QInputDialog::getText(this,"Введите тип самолета","Тип самолета");
    if(planetype.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < planetype.size();i++)
    {
        if(!planetype[i].isLetter())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString destination = QInputDialog::getText(this,"Введите место прибытия","Место прибытия");
    if(destination.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < destination.size();i++)
    {
        if(!destination[i].isLetter() && destination[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString time = QInputDialog::getText(this,"Введите время вылета","Время вылета");
    if(time.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < time.size();i++)
    {
        if(!time[i].isDigit() && time[i] != ':')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    arr[index].flightNumber = flightnumber;
    arr[index].planeType = planetype;
    arr[index].destination = destination;
    arr[index].time = time;
    arr[index].upd();
    ui->listWidget->clear();
    Schedule* current = &arr[0];
    for(int i = 0; i < arraySize;i++)
    {
        ui->listWidget->addItem(current->returnString());
        current = &arr[current->next];
    }
}


void MainWindow::on_search_2_clicked()
{
    QString number = QInputDialog::getText(this,"Введите номер рейса","Номер рейса");
    if(number.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < number.size();i++)
    {
        if(!number[i].isDigit() && number[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    ui->listWidget->clear();
    Schedule* current = &arr[0];
    for(int i = 0; i < arraySize;i++)
    {
        if(number == current->flightNumber)
            ui->listWidget->addItem(current->returnString());
        current = &arr[current->next];
    }
}


void MainWindow::on_acceptFiltr_2_clicked() // применить фильтр
{
    if(arraySize <= 0)
    {
        QMessageBox::warning(this,"Ошибка","Список пуст!");
        return;
    }
        ui->listWidget->clear();
    if(ui->filtr1_2->isChecked())
    {
        QString dest = QInputDialog::getText(this,"Введите пункт прибытия","Пункт прибытия");
        if(dest.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < dest.size();i++)
        {
            if(!dest[i].isLetter() && dest[i] != ' ')
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        Schedule* current = &arr[0];
        for(int i = 0; i < arraySize;i++)
        {
            if(dest == current->destination)
                ui->listWidget->addItem(current->returnString());
            current = &arr[current->next];
        }
    }
    else if(ui->filtr2_2->isChecked())
    {
        QString t = QInputDialog::getText(this,"Введите время вылета","Время вылета");
        if(t.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < t.size();i++)
        {
            if(!t[i].isDigit() && t[i] != ':')
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        Schedule* current = &arr[0];
        for(int i = 0; i < arraySize;i++)
        {
            if(t == current->time)
                ui->listWidget->addItem(current->returnString());
            current = &arr[current->next];
        }
    }
    else
    {
        Schedule* current = &arr[0];
        for(int i = 0; i < arraySize;i++)
        {
            ui->listWidget->addItem(current->returnString());
            current = &arr[current->next];
        }
    }

}


void MainWindow::on_sort_2_clicked()
{
    if(arraySize == 0)
    {
        QMessageBox::warning(this,"Warning","Введите данные!");
        return;
    }
    quicksort(arr,0,arraySize - 1);
    ui->listWidget->clear();
    Schedule* current = &arr[0];
    for(int i = 0; i < arraySize;i++)
    {
        ui->listWidget->addItem(current->returnString());
        current = &arr[current->next];
    }
}

