#ifndef STUDENTS_H
#define STUDENTS_H
#include <QString>

class Students
{
public:
    Students(QString name, QString group, double middleMark, double earnings);
    Students *next;
    Students *prev;
    QString name;
    QString group;
    double middleMark;
    double earnings;
    QString returnString();

};

#endif // STUDENTS_H
