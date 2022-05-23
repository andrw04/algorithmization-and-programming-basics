#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <library.h>
#include <reader.h>
#include <QInputDialog>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <promisebook.h>
#include <QDateTime>
#include <QListWidgetItem>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_openReader_clicked();

    void on_openBook_clicked();

    void on_generatePromiser_clicked();

    void on_pushButton_clicked();

    void on_findBookByAuthor_clicked();

    void on_findBookByName_clicked();

    void on_generatePromiser_2_clicked();

    void on_NumberOfBookSort_clicked();

    void on_YearSort_clicked();

    void on_showListOfBooks_clicked();

    void on_showListOfReaders_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_saveButton_clicked();

    void on_newReader_clicked();

    void on_newBook_clicked();

    void on_deleteReader_clicked();

    void on_deleteBook_clicked();

private:
    Ui::MainWindow *ui;
    Reader *readersArr;
    Library *books;
    PromiseBook *prBooks;
};
#endif // MAINWINDOW_H
