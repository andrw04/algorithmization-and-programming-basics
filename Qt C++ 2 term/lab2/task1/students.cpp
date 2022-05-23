#include "students.h"

Students::Students(QString name, QString group, double middleMark, double earnings)
{
    this->name = name;
    this->group = group;
    this->middleMark = middleMark;
    this->earnings = earnings;
    this->next = NULL;
    this->prev = NULL;
}

QString Students::returnString()
{
    return "ФИО: " + name + " гр: " + group + " ср.балл: " + QString::number(middleMark) + " доход: " + QString::number(earnings);
}
