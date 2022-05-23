#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <schedule.h>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Schedule* addFlight(Schedule *arr,QString flightNumber, QString planeType, QString destination, QString time);
    Schedule* delFlight(Schedule *Obj, int index);
    void quicksort(Schedule* arr,int first,int last);

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_inform_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_change_2_clicked();

    void on_search_2_clicked();

    void on_acceptFiltr_2_clicked();

    void on_sort_2_clicked();

private:
    Ui::MainWindow *ui;
    Schedule *arr;
    Schedule *Head;
    Schedule *Tail;
};
#endif // MAINWINDOW_H
