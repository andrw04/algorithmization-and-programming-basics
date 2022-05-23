#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <vector>
#include <shared_ptr.h>
//#include <shared_ptr.cpp>
#include <unique_ptr.h>
#include <unique_ptr.cpp>
#include <item.h>
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
    void upd();
private slots:
    void on_AddShared_clicked();

    void on_CheckUnique_clicked();

    void on_RemoveShared_clicked();

    void on_ShowSharedList_clicked();

    void on_CreateCircle_clicked();

    void on_addUnique_clicked();

    void on_removeUnique_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<SHARED_PTR<Item>> v;
};
#endif // MAINWINDOW_H
