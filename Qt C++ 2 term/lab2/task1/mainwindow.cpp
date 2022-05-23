#include "mainwindow.h"
#include "ui_mainwindow.h"

int StudentsCount = 0;
int MinFamilyEarnings = 0;

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

void MainWindow::swap( Students* a, Students* b )
{
    Students temp = *a;
    a->earnings = b->earnings;
    a->group = b->group;
    a->middleMark = b->middleMark;
    a->name = b->name;
    *b = temp;
}

Students* MainWindow::partition(Students *left, Students *right)
{
    short pivot = right->middleMark;
    // similar to i = l-1 for array implementation
    Students *i = left->prev;

    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Students *j = left; j != right; j = j->next)
    {
        if (j->middleMark <= pivot)
        {
            // Similar to i++ for array
            i = (i == NULL)? left : i->next;

            swap(i,j);
        }
    }
    i = (i == NULL)? left : i->next; // Similar to i++

    swap(i,right);
    return i;
}

void MainWindow::sorting(Students* left, Students *h)
{
    if (h != NULL && left != h && left != h->next)
    {
        Students *p = partition(left, h);
        sorting(left, p->prev);
        sorting(p->next, h);
    }
}

bool findStr(QString str1, QString str2) // str1 - большая строка, str2 - меньшая строка
{
    for(int i = 0; i < str2.size();i++)
    {
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}


void MainWindow::addStud(QString name, QString group, double middleMark, double earnings)
{
    if(StudentsCount == 0)
    {
        Head = new Students(name, group, middleMark, earnings);
        Tail = Head;
    }
    else
    {
        Tail->next = new Students(name, group, middleMark,earnings);
        Students *tmp = Tail;
        Tail = Tail->next;
        Tail->prev = tmp;
    }
    if(MinFamilyEarnings > earnings)
        MinFamilyEarnings = earnings;
    StudentsCount++;
}

void MainWindow::delStud(int x)
{
    if(StudentsCount == 0)
        return;
    if(StudentsCount == 1)
    {
        delete Head;
        StudentsCount--;
        return;
    }
    if(x == 0)
    {
        Students *old_head = Head;
        Head = Head->next;
        delete old_head;
        return;
    }
    Students *pr = Head;
    Students *cur = Head->next;
    for(int i = 1; i < StudentsCount;i++)
    {
        if(i == x)
        {
            if(cur->next == NULL)
                Tail = pr;
            pr->next = cur->next;
            StudentsCount--;
            delete cur;
            return;

        }
        pr = cur;
        cur = cur->next;
    }
}



void MainWindow::on_pushButton_2_clicked() // добавление
{
    QString name = ui->name->text();
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < name.size();i++)
    {
        if(!name[i].isLetter() && name[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString group = ui->group->text();
    if(group.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < group.size();i++)
    {
        if(!group[i].isDigit() && group[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    double middleMark = ui->marks->value();
    double earnings = ui->earnings->value();
    addStud(name,group,middleMark,earnings);
    Students *tmp = Head;
    ui->listWidget->clear();
    for(int i = 0; i < StudentsCount;i++)
    {
        ui->listWidget->addItem(tmp->returnString());
        tmp = tmp->next;
    }
}


void MainWindow::on_pushButton_3_clicked() // удаление
{
    if(StudentsCount <= 0)
    {
        QMessageBox::warning(this,"Ошибка","Список пуст!");
        return;
    }
    delStud(ui->listWidget->currentRow());
    Students *tmp = Head;
    ui->listWidget->clear();
    for(int i = 0; i < StudentsCount;i++)
    {
        ui->listWidget->addItem(tmp->returnString());
        tmp = tmp->next;
    }
}



void MainWindow::on_inform_clicked()
{
    QMessageBox::information(this,"Info","Фильтр № 1 выводит информацию о студентах, имеющих доход на члена семьи не ниже введенного значения.\n\
Фильтр № 2 выводит информацию о студентах, имеющих доход на члена семьи \
выше двух минимальных зарплат и средний балл ниже введенного");
}


void MainWindow::on_acceptFiltr_clicked()
{
    if(StudentsCount <= 0)
    {
        QMessageBox::warning(this,"Ошибка","Список пуст!");
        return;
    }
    if(ui->filtr1->isChecked())
    {
        int x = QInputDialog::getInt(this,"Введите значение","Введите доход семьи:",0,0,999999);
        Students *tmp = Head;
        ui->listWidget->clear();
        for(int i = 0; i < StudentsCount;i++)
        {
            if(tmp->earnings >= x)
                ui->listWidget->addItem(tmp->returnString());
            tmp = tmp->next;
        }
    }
    else if(ui->filtr2->isChecked())
    {
        int x = QInputDialog::getDouble(this,"Введите значение","Введите средний балл:",0,0,10);
        Students *tmp = Head;
        ui->listWidget->clear();
        for(int i = 0; i < StudentsCount;i++)
        {
            if(tmp->middleMark < x && tmp->earnings > 2 * MinFamilyEarnings)
                ui->listWidget->addItem(tmp->returnString());
            tmp = tmp->next;
        }
    }
    else
    {
        Students *tmp = Head;
        ui->listWidget->clear();
        for(int i = 0; i < StudentsCount;i++)
        {
            ui->listWidget->addItem(tmp->returnString());
            tmp = tmp->next;
        }
    }
}


void MainWindow::on_search_clicked() // поиск по фамилии
{
    QString name = QInputDialog::getText(this,"Введите фамилию","Фамилия:");
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < name.size();i++)
    {
        if(!name[i].isLetter() && name[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    Students *tmp = Head;
    ui->listWidget->clear();
    for(int i = 0; i < StudentsCount;i++)
    {
        if(findStr(tmp->name,name))
            ui->listWidget->addItem(tmp->returnString());
        tmp = tmp->next;
    }
}


void MainWindow::on_sort_clicked() // квиксорт
{
    sorting(Head,Tail);
    Students *tmp = Head;
    ui->listWidget->clear();
    for(int i = 0; i < StudentsCount;i++)
    {
        ui->listWidget->addItem(tmp->returnString());
        tmp = tmp->next;
    }
}


void MainWindow::on_pushButton_clicked() // добавить из файла
{
    QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл", "C:\\","TXT File (*.txt)"));
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString name = in.readLine();
        if(name.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < name.size();i++)
        {
            if(!name[i].isLetter() && name[i] != ' ')
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString group = in.readLine();
        if(group.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < group.size();i++)
        {
            if(!group[i].isDigit())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString middleMark = in.readLine();
        if(middleMark.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < middleMark.size();i++)
        {
            if(!middleMark[i].isDigit() && middleMark[i] != '.')
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString earnings = in.readLine();
        if(earnings.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < earnings.size();i++)
        {
            if(!earnings[i].isDigit() && earnings[i] != '.')
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        addStud(name,group,middleMark.toDouble(),earnings.toDouble());
    }
    Students *tmp = Head;
    ui->listWidget->clear();
    for(int i = 0; i < StudentsCount;i++)
    {
        ui->listWidget->addItem(tmp->returnString());
        tmp = tmp->next;
    }
}


void MainWindow::on_change_clicked()
{
    int index = ui->listWidget->currentRow();
    Students *cur = Head;
    QString name = QInputDialog::getText(this,"Введите данные","Введите ФИО:");
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < name.size();i++)
    {
        if(!name[i].isLetter() && name[i] != ' ')
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString group = QInputDialog::getText(this,"Введите данные","Введите номер группы:");
    if(group.isEmpty() || group.size() != 6)
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < group.size();i++)
    {
        if(!group[i].isDigit())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    double middleMark = QInputDialog::getDouble(this,"Введите данные","Введите средний балл",0,0,10);
    double earnings = QInputDialog::getDouble(this,"Введите данные","Введите доход:",0,0,999999);
    for(int i = 0; i < index;i++)
    {
        cur = cur->next;
    }
    cur->name = name;
    cur->group = group;
    cur->middleMark = middleMark;
    cur->earnings = earnings;
    Students *tmp = Head;
    ui->listWidget->clear();
    for(int i = 0; i < StudentsCount;i++)
    {
        ui->listWidget->addItem(tmp->returnString());
        tmp = tmp->next;
    }
}


void MainWindow::on_pushButton_4_clicked() // сохранить
{
    QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл", "C:\\","TXT File (*.txt)"));
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Cannot open file for writing");
    }
    QTextStream out(&file);
    Students *tmp = Head;
    for(int i = 0; i < StudentsCount;i++)
    {
        out << tmp->name << '\n' << tmp->group << '\n' << tmp->middleMark << '\n' << tmp->earnings << '\n';
        tmp = tmp->next;
    }
}

