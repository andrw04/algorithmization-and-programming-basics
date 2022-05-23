#include "library.h"

Library::Library()
{

}

void Library::setData(int bCode, QString aut, QString bName, int y, QString lang)
{
    bookCode = bCode;
    author = aut;
    bookName = bName;
    year = y;
    language = lang;
}

QString Library::returnString()
{
    QString itm = " Код книги: " + QString::number(bookCode) + " Автор: " + author + " Название книги: " + bookName + " Год: " + QString::number(year) + " Язык: " + language;
    return itm;
}

int Library::returnBookCode()
{
    return bookCode;
}

QString Library::returnAuthor()
{
    return author;
}

QString Library::returnBookName()
{
    return bookName;
}

int Library::returnYear()
{
    return year;
}
