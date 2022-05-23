#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <string.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool parseFunc(std::string str, int StrNum);
    void parseVariable(std::string str, int strNum);
    void checkIntCount(std::string str, int StrNum);
    void checkDoubleCount(std::string str, int StrNum);
    void checkFloatCount(std::string str, int StrNum);
    void checkCharCount(std::string str, int StrNum);
    void checkShortCount(std::string str, int StrNum);
    void checkLongCount(std::string str, int StrNum);
    void checkBoolCount(std::string str, int StrNum);
    void parseVariableForFunc(std::string str);
    void parseArray(std::string str);
    void parseClassNStruct(std::string str);
    void parseChangeVariable(std::string str, int StrCount);
    void check_local(std::string str);
    bool overloadCheck(std::string str);
    void ifElseDeep(std::string str);
    void findLogicError(std::string str);
    void reset();

private slots:
    void on_inputFile_clicked();

    void on_parse_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<std::string> funcList;
    std::vector<std::string> varList;
    std::vector<std::pair<int,int>> changeVarPos;
    std::vector<int> localVar;
    std::vector<int> funcOverload;
    std::vector<int> ifElseDeepList;
};
#endif // MAINWINDOW_H
