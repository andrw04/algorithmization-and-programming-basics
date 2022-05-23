#ifndef READER_H
#define READER_H
#include <QString>
class Reader
{
public:
    Reader();
    void setData(QString n,int readerCode,QString home,QString phone);
    QString returnString();
    int returnReaderCode();
    QString returnName();
public:
    QString name; // Ф.И.О
    int rCode; // код читателя
    QString homeAddress; // домашний адрес
    QString phoneNumber; // контактный телефон


};

#endif // READER_H
