#include "reader.h"

Reader::Reader()
{

}

void Reader::setData(QString n,int readerCode,QString home,QString phone)
{
    name = n;
    rCode = readerCode;
    homeAddress = home;
    phoneNumber = phone;
}

QString Reader::returnString()
{
    QString itm = "Ф.И.О: " + name + " Номер: " + QString::number(rCode) + " Адрес: " + homeAddress + " тел: " + phoneNumber;
    return itm;
}

int Reader::returnReaderCode()
{
    return rCode;
}

QString Reader::returnName()
{
    return name;
}
