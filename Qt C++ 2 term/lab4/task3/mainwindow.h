#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<QInputDialog>
#include <QMessageBox>
#include <vector.h>
#include <vector>

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
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void Normalize(std::vector<int>& c);
    void AddZero(std::vector<int>& c, int x);
    std::vector<int> AddNum(const std::vector<int>& a, const std::vector<int>& b, int k);
    int GetBit(const std::vector<int>& v, int b);
    std::vector<int> Multiply(const std::vector<int>& a, int x, int k);
    void GenerateSequence(std::vector<int> n, const std::vector<std::vector<int>>& p, int k, int i, std::vector<std::pair<int, std::vector<int>> >& v);
};
#endif // MAINWINDOW_H
