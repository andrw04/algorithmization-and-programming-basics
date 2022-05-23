#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <QString>
#include <QDateTimeEdit>

class Schedule
{
public:
    Schedule();
    Schedule(QString flightNumber,QString planeType, QString destination, QString time);
    QString returnString();
    void upd();
    int minuts;
    int next;
    int prev;
    QString flightNumber;
    QString planeType;
    QString destination;
    QString time;
};

#endif // SCHEDULE_H
