#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <deque.h>
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
    void on_push_back_clicked();

    void on_push_front_clicked();

    void on_pop_back_clicked();

    void on_pop_front_clicked();

    void on_back_clicked();

    void on_front_clicked();

    void on_empty_clicked();

    void on_size_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    Deque<int> *deq;
};
#endif // MAINWINDOW_H
