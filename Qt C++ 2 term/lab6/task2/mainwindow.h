#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <hashtable.h>
#include <QString>
#include <QMessageBox>
#include <findmaxkey.h>

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
    void on_add_clicked();

    void on_reset_clicked();

    void on_find_clicked();

    void on_print_clicked();

    void on_clear_clicked();

    void on_random_clicked();

    void on_Print_t2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    HashTable<QString> *table;
    FindMaxKey *fmk;
};
#endif // MAINWINDOW_H
