#include "schedule.h"

Schedule::Schedule()
{

}

Schedule::Schedule(QString flightNumber, QString planeType, QString destination, QString time)
{
    this->flightNumber = flightNumber;
    this->planeType = planeType;
    this->destination = destination;
    this->time = time;
    this->next = NULL;
    this->prev = NULL;
    QString t = time;
    QString hours = t.remove(2,3);
    t = time;
    QString m = t.remove(0,3);
    this->minuts =  hours.toInt() * 60 + m.toInt();
}

QString Schedule::returnString()
{
    QString res = "№ рейса " + flightNumber + " тип самолета: " + planeType + " пункт прибытия: " + destination + " время вылета: " + time;
    return res;
}

void Schedule::upd()
{
    QString t = time;
    QString hours = t.remove(2,3);
    t = time;
    QString m = t.remove(0,3);
    this->minuts =  hours.toInt() * 60 + m.toInt();
}
