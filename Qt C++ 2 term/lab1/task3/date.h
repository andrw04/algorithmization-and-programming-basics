#ifndef DATE_H
#define DATE_H
#include <QString>

class Date
{
public:
    Date();
    void setDate(QString d,QString m,QString y);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBithday(Date bithdaydate);
    int Duration(Date date);
    QString returnString();
public:
    QString day;
    QString month;
    QString year;
};

#endif // DATE_H
