#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack.h>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <doublestack.h>
#include <variables.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString ConvertToOPW(QString InputStr);
    double GetResultOPW(QString InputStr,double a,double b,double c,double d,double e);
    double GetResult(QString InputStr,double a,double b,double c,double d,double e);

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Stack *stack;
    Stack *operatorStr;
    DoubleStack *doubleStack;
    QString *expressions;
    QString *values;
};
#endif // MAINWINDOW_H
