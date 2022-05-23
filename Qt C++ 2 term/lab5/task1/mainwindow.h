#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <queue.h>
#include <queue.cpp>
#include <QMessageBox>
#include <QImage>
#include <viewimage.h>

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
    void on_push_clicked();

    void on_pop_clicked();

    void on_size_clicked();

    void on_front_clicked();

    void on_back_clicked();

    void on_empty_clicked();

    void on_load_img_clicked();

    void on_left_clicked();

    void on_right_clicked();

private:
    Ui::MainWindow *ui;
    Queue<int> *q;
    ViewImage *v;
};
#endif // MAINWINDOW_H
