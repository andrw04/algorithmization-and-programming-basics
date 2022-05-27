#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <binarytree.h>
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
    void on_show_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_from_array_clicked();

    void on_reset_clicked();

    void on_find_clicked();

    //void on_balance_clicked();

    void on_individual_task_clicked();

private:
    Ui::MainWindow *ui;
    BinaryTree *tree;
};
#endif // MAINWINDOW_H
