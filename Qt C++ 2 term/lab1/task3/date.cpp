#include "date.h"

Date::Date()
{

}

void Date::setDate(QString d, QString m, QString y)
{
    day = d;
    month = m;
    year = y;
}

Date Date::NextDay()
{
    Date next;
    next.setDate(day,month,year);
    switch(month.toInt())
    {
    case 1:
        if(day == "31")
        {
            next.day = "01";
            next.month = "02";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 2:
        if((day == "29" && this->IsLeap()) || (day == "28" && !(this->IsLeap())))
        {
            next.day = "01";
            next.month = "03";
        }
        else
        {
            next.day = QString::number(day.toInt() + 1);
        }
        break;
    case 3:
        if(day == "31")
        {
            next.day = "01";
            next.month = "04";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 4:
        if(day == "30")
        {
            next.day = "01";
            next.month = "05";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 5:
        if(day == "31")
        {
            next.day = "01";
            next.month = "06";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 6:
        if(day == "30")
        {
            next.day = "01";
            next.month = "07";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 7:
        if(day == "31")
        {
            next.day = "01";
            next.month = "08";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 8:
        if(day == "31")
        {
            next.day = "01";
            next.month = "09";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 9:
        if(day == "30")
        {
            next.day = "01";
            next.month = "10";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 10:
        if(day == "31")
        {
            next.day = "01";
            next.month = "11";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 11:
        if(day == "30")
        {
            next.day = "01";
            next.month = "12";
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    case 12:
        if(day == "31")
        {
            next.day = "01";
            next.month = "01";
            next.year = QString::number(year.toInt()+1);
        }
        else
        {
            if(day.toInt() + 1 < 10)
            {
                next.day = "0" + QString::number(day.toInt() + 1);
            }
            else
            {
                next.day = QString::number(day.toInt() + 1);
            }
        }
        break;
    }
    return next;
}

Date Date::PreviousDay()
{
    Date previous;
    previous.setDate(day,month,year);
    switch(month.toInt())
    {
    case 1:
        if(day == "01"){
            previous.day = "31";
            previous.month = "12";
            if(year == "0000")
                previous.year = "0000";
            else if(year.toInt() < 10)
                previous.year = "000" + QString::number(year.toInt() - 1);
            else if(year.toInt() < 100)
                previous.year = "00" + QString::number(year.toInt() - 1);
            else if(year.toInt() < 1000)
                previous.year = "0" + QString::number(year.toInt() - 1);
            else
                previous.year = QString::number(year.toInt() - 1);

        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1 );
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 2:
        if(day == "01")
        {
            previous.day = "31";
            previous.month = "01";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 3:
        if(day == "01" && this->IsLeap())
        {
            previous.day = "29";
            previous.month = "02";
        }
        else if(day == "01" && !(this->IsLeap()))
        {
            previous.day = "28";
            previous.month = "02";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 4:
        if(day == "01")
        {
            previous.day = "31";
            previous.month = "03";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 5:
        if(day == "01")
        {
            previous.day = "30";
            previous.month = "04";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 6:
        if(day == "01")
        {
            previous.day = "31";
            previous.month = "05";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 7:
        if(day == "01")
        {
            previous.day = "30";
            previous.month = "06";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 8:
        if(day == "01")
        {
            previous.day = "31";
            previous.month = "07";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 9:
        if(day == "01")
        {
            previous.day = "31";
            previous.month = "08";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 10:
        if(day == "01")
        {
            previous.day = "30";
            previous.month = "09";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 11:
        if(day == "01")
        {
            previous.day = "31";
            previous.month = "10";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    case 12:
        if(day == "01")
        {
            previous.day = "30";
            previous.month = "11";
        }
        else
        {
            if(day.toInt() < 10)
            {
                previous.day = "0" + QString::number(day.toInt() -1);
            }
            else
            {
                previous.day = QString::number(day.toInt() - 1);
            }
        }
        break;
    }
    return previous;
}

bool Date::IsLeap()
{
    if(year.toInt() % 4 == 0)
        return true;
    else
        return false;
}

short Date::WeekNumber()
{
    Date ny;
    ny.setDate("01","01",year);
    int week = Duration(ny) / 7;
    return week;
}

int Date::DaysTillYourBithday(Date birthdaydate)
{
    return this->Duration(birthdaydate)   ;
}

int Date::Duration(Date date)
{
    int days = 0;
    if(date.year.toInt() < year.toInt() || (date.year.toInt() == year.toInt() && date.month.toInt() < month.toInt()) ||
            (date.year.toInt() == year.toInt() && date.month.toInt() == month.toInt() && date.day.toInt() < day.toInt()))
    {
        while(date.month.toInt() != month.toInt() || date.day.toInt() != day.toInt())
        {
            date = date.NextDay();
            days++;
        }
        while(date.year.toInt() < year.toInt())
        {
            if(date.year.toInt() % 4 == 0)
                days++;
            days += 365;
            date.year = QString::number(date.year.toInt() + 1);
        }
    }
    else
    {
        while(date.month.toInt() != month.toInt() || date.day.toInt() != day.toInt())
        {
            date = date.PreviousDay();
            days++;
        }
        while(date.year.toInt() > year.toInt())
        {
            if(date.year.toInt() % 4 == 0)
                days++;
            days += 365;
            date.year = QString::number(date.year.toInt() - 1);
        }
    }

    return days;
}

QString Date::returnString()
{
    QString q = day + "." + month + "." + year;
    return q;
}
