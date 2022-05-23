#include "promisebook.h"

PromiseBook::PromiseBook()
{

}

void PromiseBook::setData(Library book, Reader person, QDate date)
{
    rCode = person.returnReaderCode();
    bCode = book.returnBookCode();
    dateOfIssue = date;
    QDate tmp = dateOfIssue;
    returnDate = tmp.addDays(10);
    realReturnDate = dateOfIssue.addDays(rand() % 25);

}

QString PromiseBook::returnString()
{
    QString itm = "Номер читателя: " + QString::number(rCode) + " Номер книги: " + QString::number(bCode) + " Дата выдачи : " + dateOfIssue.toString() + " Дата сдачи: " + returnDate.toString() + " Реальная дата: " + realReturnDate.toString();
    return itm;
}

bool PromiseBook::debt() // true - должник false - не должник
{
    if(returnDate.daysTo(realReturnDate) > 10)
        return true;
    else
        return false;

}

int PromiseBook::returnReaderCode()
{
    return rCode;
}
