#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <set.h>
#include <map.h>
#include <unordered_map.h>
#include <string>
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

private slots:

    void on_Contains_clicked();

    void on_ChangeValue_clicked();

    void on_GetValue_clicked();

    void on_Insert_clicked();

    void on_Erase_clicked();

    void on_Clear_clicked();

    void on_Show_clicked();

    void on_Show_map_clicked();

    void on_Insert_map_clicked();

    void on_Insert_set_clicked();

    void on_show_set_clicked();

    void on_pushButton_clicked();

    void on_delete_set_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::MainWindow *ui;

    UNORDERED_MAP<int, std::string>* unordered_map;
    MAP<int,std::string>* map;
    SET<int>* set;
};
#endif // MAINWINDOW_H
