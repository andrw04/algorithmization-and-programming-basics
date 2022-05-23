#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <students.h>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addStud(QString name, QString group, double middleMark, double earnings);
    void delStud(int i);
    void swap( Students* a, Students* b );
    Students* partition(Students *left, Students *right);
    void sorting(Students* left, Students *h);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_inform_clicked();

    void on_acceptFiltr_clicked();

    void on_search_clicked();

    void on_sort_clicked();

    void on_pushButton_clicked();

    void on_change_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Students *Head;
    Students *Tail;
};
#endif // MAINWINDOW_H
