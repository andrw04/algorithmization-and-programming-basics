#ifndef PROMISEBOOK_H
#define PROMISEBOOK_H
#include <QString>
#include <reader.h>
#include <library.h>
#include <QDate>

class PromiseBook
{
public:
    PromiseBook();
    void setData(Library book,Reader person ,QDate date);
    QString returnString();
    bool debt();
    int returnReaderCode();
public:
    int rCode;
    int bCode;
    QDate dateOfIssue;
    QDate returnDate;
    QDate realReturnDate;
};

#endif // PROMISEBOOK_H
