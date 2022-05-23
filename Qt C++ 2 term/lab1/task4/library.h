#ifndef LIBRARY_H
#define LIBRARY_H
#include <QString>

class Library
{
public:
    Library();
    void setData(int bCode, QString aut, QString bName,int y,QString lang);
    QString returnString();
    int returnBookCode();
    QString returnAuthor();
    QString returnBookName();
    int returnYear();
public:
    int bookCode; // код книги
    QString author; // фамилия автора
    QString bookName; // название книги
    int year; // год издания
    QString language; // язык издания

};

#endif // LIBRARY_H
