#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <date.h>
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>
#include <fstream>

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
    void on_pushButton_clicked();

    void on_next_clicked();

    void on_prev_clicked();

    void on_leap_clicked();

    void on_weekNumber_clicked();

    void on_tillBirthday_clicked();

    void on_duration_clicked();

    void on_fileOpen_clicked();

    void on_Save_clicked();

    void on_show_clicked();

    void on_add_clicked();

    void on_add_2_clicked();

private:
    Ui::MainWindow *ui;
    Date birthday;
    Date *dates;
};
#endif // MAINWINDOW_H
