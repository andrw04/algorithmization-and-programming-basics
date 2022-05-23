#include "mainwindow.h"
#include "ui_mainwindow.h"
int VARIABLE_COUNT = 0;
int ARRAY_COUNT = 0;
int CLASS_COUNT = 0;
int STRUCT_COUNT = 0;
bool local = false; // индикатор для локальной переменной
int counter = 0; // счётчик скобок для локальных переменных
int IfElseCounter = 0; // счётчик скобок
int IfCount = 0; // количество if-ов

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::parseFunc(std::string str, int StrNum)
{
    bool noFunc = true;
    std::regex regularIntFunc("(int)"
                              "([\\s]*)"
                              "([\\w:]+)"
                              "([\\Q()\\E]+)"
                              "([\\w\\s:=,-]*)"
                              "([\\Q()\\E])");
    std::cmatch regIntFunc;
    if(std::regex_search(str.c_str(),regIntFunc,regularIntFunc))
    {
        if(overloadCheck(regIntFunc.str()))
        {
            funcOverload.push_back(StrNum);
        }
        funcList.push_back(regIntFunc.str());
        noFunc = false;
    }
    std::regex regularDoubleFunc("(double)"
                                 "([\\s]*)"
                                 "([\\w:]+)"
                                 "([\\Q()\\E]+)"
                                 "([\\w\\s:=,-]*)"
                                 "([\\Q()\\E])");
    std::cmatch regDoubleFunc;
    if(std::regex_search(str.c_str(),regDoubleFunc,regularDoubleFunc))
    {
        if(overloadCheck(regDoubleFunc.str()))
        {
            funcOverload.push_back(StrNum);
        }
        funcList.push_back(regDoubleFunc.str());
        noFunc = false;
    }
    std::regex regularVoidFunc("(void)"
                               "([\\s]*)"
                               "([\\w:]+)"
                               "([\\Q()\\E]+)"
                               "([\\w\\s:=,-]*)"
                               "([\\Q()\\E])");
    std::cmatch regVoidFunc;
    if(std::regex_search(str.c_str(),regVoidFunc,regularVoidFunc))
    {
        if(overloadCheck(regVoidFunc.str()))
        {
            funcOverload.push_back(StrNum);
        }
        funcList.push_back(regVoidFunc.str());
        noFunc = false;
    }
    std::regex regularShortFunc("(short)"
                                "([\\s]*)"
                                "([\\w:]+)"
                                "([\\Q()\\E]+)"
                                "([\\w\\s:=,-]*)"
                                "([\\Q()\\E])");
    std::cmatch regShortFunc;
    if(std::regex_search(str.c_str(),regShortFunc,regularShortFunc))
    {
        if(overloadCheck(regShortFunc.str()))
        {
            funcOverload.push_back(StrNum);
        }
        funcList.push_back(regShortFunc.str());
        noFunc = false;
    }
    std::regex regularFloatFunc("(float)"
                                "([\\s]*)"
                                "([\\w:]+)"
                                "([\\Q()\\E]+)"
                                "([\\w\\s:=,-]*)"
                                "([\\Q()\\E])");
    std::cmatch regFloatFunc;
    if(std::regex_search(str.c_str(),regFloatFunc,regularFloatFunc))
    {
        if(overloadCheck(regFloatFunc.str()))
        {
            funcOverload.push_back(StrNum);
        }
        funcList.push_back(regFloatFunc.str());
        noFunc = false;
    }
    std::regex regularBoolFunc("(bool)"
                               "([\\s]*)"
                               "([\\w:]+)"
                               "([\\Q()\\E]+)"
                               "([\\w\\s:=,-]*)"
                               "([\\Q()\\E])");
    std::cmatch regBoolFunc;
    if(std::regex_search(str.c_str(),regBoolFunc,regularBoolFunc))
    {
        if(overloadCheck(regBoolFunc.str()))
        {
            funcOverload.push_back(StrNum);
        }
        funcList.push_back(regBoolFunc.str());
        noFunc = false;
    }
    std::regex regularLongFunc("(long)"
                               "([\\s]*)"
                               "([\\w:]+)"
                               "([\\Q()\\E]+)"
                               "([\\w\\s:=,-]*)"
                               "([\\Q()\\E])");
    std::cmatch regLongFunc;
    if(std::regex_search(str.c_str(),regLongFunc,regularLongFunc))
    {
        if(overloadCheck(regLongFunc.str()))
        {
            funcOverload.push_back(StrNum);
        }
        funcList.push_back(regLongFunc.str());
        noFunc = false;
    }
    std::regex regularCharFunc("(char)"
                               "([\\s]*)"
                               "([\\w:]+)"
                               "([\\Q()\\E]+)"
                               "([\\w\\s:=,-]*)"
                               "([\\Q()\\E])");
    std::cmatch regCharFunc;
    if(std::regex_search(str.c_str(),regCharFunc,regularCharFunc))
    {
        if(overloadCheck(regCharFunc.str()))
        {
            funcOverload.push_back(StrNum);
        }
        funcList.push_back(regCharFunc.str());
        noFunc = false;
    }
    return noFunc;
}

void MainWindow::parseVariable(std::string str, int strNum)
{
    std::regex regularInt("(int)"
                          "([\\*]*)"
                          "([\\s]+)"
                          "([\\w\\s\\Q+*,/=\\E-]*[^;\\n])"
                          "(;)");
    std::cmatch regInt;
    if(std::regex_search(str.c_str(),regInt,regularInt))
    {
        checkIntCount(regInt.str(), strNum);
    }
    std::regex regularDouble("(double)"
                             "([\\*]*)"
                             "([\\s]+)"
                             "([\\w\\s\\Q+*,/=.\\E-]*[^;\\n])"
                             "(;)");
    std::cmatch regDouble;
    if(std::regex_search(str.c_str(),regDouble,regularDouble))
    {
        checkDoubleCount(regDouble.str(), strNum);
    }
    std::regex regularFloat("(float)"
                           "([\\*]*)"
                           "([\\s]+)"
                           "([\\w\\s\\Q+*,/=.\\E-]*[^;\\n])"
                           "(;)");
    std::cmatch regFloat;
    if(std::regex_search(str.c_str(),regFloat,regularFloat))
    {
        checkFloatCount(regFloat.str(), strNum);
    }
    std::regex regularChar("(char)"
                           "([\\*]*)"
                           "([\\s]+)"
                           "([\\w\\s\\Q+*,/='\\E-]*[^;\\n])"
                           "(;)");
    std::cmatch regChar;
    if(std::regex_search(str.c_str(),regChar,regularChar))
    {
        checkCharCount(regChar.str(), strNum);
    }
    std::regex regularShort("(short)"
                            "([\\*]*)"
                            "([\\s]+)"
                            "([\\w\\s\\Q+*,/=\\E-]*[^;\\n])"
                            "(;)");
    std::cmatch regShort;
    if(std::regex_search(str.c_str(),regShort,regularShort))
    {
        checkShortCount(regShort.str(), strNum);
    }
    std::regex regularLong("(long)"
                          "([\\*]*)"
                          "([\\s]+)"
                          "([\\w\\s\\Q+*,/=\\E-]*[^;\\n])"
                          "(;)");
    std::cmatch regLong;
    if(std::regex_search(str.c_str(),regLong,regularLong))
    {
        checkLongCount(regLong.str(), strNum);
    }
    std::regex regularBool("(bool)"
                          "([\\*]*)"
                          "([\\s]+)"
                          "([\\w\\s\\Q+*,/=\\E-]*[^;\\n])"
                          "(;)");
    std::cmatch regBool;
    if(std::regex_search(str.c_str(),regBool,regularBool))
    {
        checkBoolCount(regBool.str(), strNum);
    }
}

void MainWindow::checkIntCount(std::string str, int StrNum)
{
    std::regex regular("([\\*]*)"
                       "([\\s]+)"
                       "([\\*]*)"
                       "([\\w]+)"
                       "([\\w\\s\\Q+*,/=\\E-]*)");
    std::cmatch reg;
    QString tmp = QString::fromStdString(str);
    std::regex regularArray("(int)"
                            "([\\s]+)"
                            "([\\w]+)"
                            "(\\[[\\w\\s]*\\])");
    std::cmatch regArray;
    QStringList tmpList = tmp.split(',');
    for(int i = 0; i < tmpList.size();i++)
    {
        std::string t1 = tmpList[i].toStdString();
        if(std::regex_search(t1.c_str(),reg,regular) && std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
        else if(std::regex_search(t1.c_str(),reg,regular))
        {
            varList.push_back(("int" + QString::fromStdString(reg.str())).toStdString());
            //ui->outputBox->append("int" + QString::fromStdString(reg.str()));
            VARIABLE_COUNT++;
            if(local)
            {
                localVar.push_back(StrNum);
            }
        }
        else if(std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
    }
}

void MainWindow::checkDoubleCount(std::string str, int StrNum)
{
    std::regex regular("([\\*]*)"
                       "([\\s]+)"
                       "([\\*]*)"
                       "([\\w]+)"
                       "([\\w\\s\\Q+*,/=.\\E-]*)");
    std::cmatch reg;
    QString tmp = QString::fromStdString(str);
    std::regex regularArray("(double)"
                            "([\\s]+)"
                            "([\\w]+)"
                            "(\\[[\\w\\s]*\\])");
    std::cmatch regArray;
    QStringList tmpList = tmp.split(',');
    for(int i = 0; i < tmpList.size();i++)
    {
        std::string t1 = tmpList[i].toStdString();
        if(std::regex_search(t1.c_str(),reg,regular) && std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
        else if(std::regex_search(t1.c_str(),reg,regular))
        {
            varList.push_back(("double" + QString::fromStdString(reg.str())).toStdString());
            //ui->outputBox->append("int" + QString::fromStdString(reg.str()));
            VARIABLE_COUNT++;
            if(local)
            {
                localVar.push_back(StrNum);
            }
        }
        else if(std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
    }
}

void MainWindow::checkFloatCount(std::string str, int StrNum)
{
    std::regex regular("([\\*]*)"
                       "([\\s]+)"
                       "([\\*]*)"
                       "([\\w]+)"
                       "([\\w\\s\\Q+*,/=.\\E-]*)");
    std::cmatch reg;
    QString tmp = QString::fromStdString(str);
    std::regex regularArray("(float)"
                            "([\\s]+)"
                            "([\\w]+)"
                            "(\\[[\\w\\s]*\\])");
    std::cmatch regArray;
    QStringList tmpList = tmp.split(',');
    for(int i = 0; i < tmpList.size();i++)
    {
        std::string t1 = tmpList[i].toStdString();
        if(std::regex_search(t1.c_str(),reg,regular) && std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
        else if(std::regex_search(t1.c_str(),reg,regular))
        {
            varList.push_back(("float" + QString::fromStdString(reg.str())).toStdString());
            //ui->outputBox->append("int" + QString::fromStdString(reg.str()));
            VARIABLE_COUNT++;
            if(local)
            {
                localVar.push_back(StrNum);
            }
        }
        else if(std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
    }
}

void MainWindow::checkCharCount(std::string str, int StrNum)
{
    std::regex regular("([\\*]*)"
                       "([\\s]+)"
                       "([\\*]*)"
                       "([\\w]+)"
                       "([\\w\\s\\Q+*,/='\\E-]*)");
    std::cmatch reg;
    QString tmp = QString::fromStdString(str);
    std::regex regularArray("(char)"
                            "([\\s]+)"
                            "([\\w]+)"
                            "(\\[[\\w\\s]*\\])");
    std::cmatch regArray;
    QStringList tmpList = tmp.split(',');
    for(int i = 0; i < tmpList.size();i++)
    {
        std::string t1 = tmpList[i].toStdString();
        if(std::regex_search(t1.c_str(),reg,regular) && std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
        else if(std::regex_search(t1.c_str(),reg,regular))
        {
            varList.push_back(("char" + QString::fromStdString(reg.str())).toStdString());
            //ui->outputBox->append("int" + QString::fromStdString(reg.str()));
            VARIABLE_COUNT++;
            if(local)
            {
                localVar.push_back(StrNum);
            }
        }
        else if(std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
    }
}

void MainWindow::checkShortCount(std::string str, int StrNum)
{
    std::regex regular("([\\*]*)"
                       "([\\s]+)"
                       "([\\*]*)"
                       "([\\w]+)"
                       "([\\w\\s\\Q+*,/=\\E-]*)");
    std::cmatch reg;
    QString tmp = QString::fromStdString(str);
    std::regex regularArray("(short)"
                            "([\\s]+)"
                            "([\\w]+)"
                            "(\\[[\\w\\s]*\\])");
    std::cmatch regArray;
    QStringList tmpList = tmp.split(',');
    for(int i = 0; i < tmpList.size();i++)
    {
        std::string t1 = tmpList[i].toStdString();
        if(std::regex_search(t1.c_str(),reg,regular) && std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
        else if(std::regex_search(t1.c_str(),reg,regular))
        {
            varList.push_back(("short" + QString::fromStdString(reg.str())).toStdString());
            //ui->outputBox->append("int" + QString::fromStdString(reg.str()));
            VARIABLE_COUNT++;
            if(local)
            {
                localVar.push_back(StrNum);
            }
        }
        else if(std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
    }
}

void MainWindow::checkLongCount(std::string str, int StrNum)
{
    std::regex regular("([\\*]*)"
                       "([\\s]+)"
                       "([\\*]*)"
                       "([\\w]+)"
                       "([\\w\\s\\Q+*,/=\\E-]*)");
    std::cmatch reg;
    QString tmp = QString::fromStdString(str);
    std::regex regularArray("(long)"
                            "([\\s]+)"
                            "([\\w]+)"
                            "(\\[[\\w\\s]*\\])");
    std::cmatch regArray;
    QStringList tmpList = tmp.split(',');
    for(int i = 0; i < tmpList.size();i++)
    {
        std::string t1 = tmpList[i].toStdString();
        if(std::regex_search(t1.c_str(),reg,regular) && std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
        else if(std::regex_search(t1.c_str(),reg,regular))
        {
            varList.push_back(("long" + QString::fromStdString(reg.str())).toStdString());
            //ui->outputBox->append("int" + QString::fromStdString(reg.str()));
            VARIABLE_COUNT++;
            if(local)
            {
                localVar.push_back(StrNum);
            }
        }
        else if(std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
    }
}

void MainWindow::checkBoolCount(std::string str, int StrNum)
{
    std::regex regular("([\\*]*)"
                       "([\\s]+)"
                       "([\\*]*)"
                       "([\\w]+)"
                       "([\\w\\s\\Q+*,/=\\E-]*)");
    std::cmatch reg;
    QString tmp = QString::fromStdString(str);
    std::regex regularArray("(bool)"
                            "([\\s]+)"
                            "([\\w]+)"
                            "(\\[[\\w\\s]*\\])");
    std::cmatch regArray;
    QStringList tmpList = tmp.split(',');
    for(int i = 0; i < tmpList.size();i++)
    {
        std::string t1 = tmpList[i].toStdString();
        if(std::regex_search(t1.c_str(),reg,regular) && std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
        else if(std::regex_search(t1.c_str(),reg,regular))
        {
            varList.push_back(("bool" + QString::fromStdString(reg.str())).toStdString());
            //ui->outputBox->append("int" + QString::fromStdString(reg.str()));
            VARIABLE_COUNT++;
            if(local)
            {
                localVar.push_back(StrNum);
            }
        }
        else if(std::regex_search(t1.c_str(),regArray,regularArray))
        {
            ARRAY_COUNT++;
        }
    }
}


void MainWindow::parseArray(std::string str)
{
    std::regex regularIntArray("(int)"
                               "([\\s]+)"
                               "([\\w]+)"
                               "(\\[[\\w\\s]*\\])");
    std::cmatch regIntArray;
    if(std::regex_search(str.c_str(),regIntArray,regularIntArray))
    {
        checkIntCount(regIntArray.str(),0);
        //ui->outputBox->append(QString::fromStdString(regIntArray.str()) + ']');
    }
}

void MainWindow::parseClassNStruct(std::string str)
{
    std::regex regularClass("(class)");
    std::cmatch regClass;
    std::regex regularStruct("(struct)");
    std::cmatch regStruct;
    if(std::regex_search(str.c_str(),regClass,regularClass))
    {
        CLASS_COUNT++;
    }
    if(std::regex_search(str.c_str(),regStruct,regularStruct))
    {
        STRUCT_COUNT++;
    }
}

void MainWindow::parseChangeVariable(std::string str, int StrCount)
{
    std::regex regularChange("([\\s]*)""(=)""([\\s]*)");
    std::cmatch regChange;
    if(std::regex_search(str.c_str(),regChange,regularChange))
    {
        for(size_t i = 0; i < str.size();i++)
        {
            if(str[i] == '=')
            {
                changeVarPos.push_back(std::make_pair(StrCount,i));
                return;
            }
        }
    }
}

void MainWindow::check_local(std::string str)
{
    for(size_t i = 0; i < str.size();i++)
    {
        if(str[i] == '{')
            counter++;
        if(str[i] == '}')
            counter--;
    }
    if(counter > 0)
        local = true;
    else
        local = false;
}

bool MainWindow::overloadCheck(std::string str)
{
        std::regex regular("[\\.]*[\\(]");
        std::cmatch reg1;
        std::cmatch reg2;
        for(size_t i = 0; i < funcList.size();i++)
        {
            if(std::regex_search(str.c_str(),reg1,regular) && std::regex_search(funcList[i].c_str(),reg2,regular))
            {
                if(reg1.str() == reg2.str())
                {
                    return true;
                }
            }
        }
        return false;
}

void MainWindow::ifElseDeep(std::string str)
{
    std::regex regular("(if)"
                       "([\\s]*)"
                       "\\(");
    std::cmatch reg;
    if(std::regex_search(str.c_str(),reg,regular))
    {
        if(IfElseCounter == IfCount)
            IfCount++;
        IfElseCounter++;
    }
    for(size_t i = 0; i < str.size();i++)
    {
        if(str[i] == '}' && IfElseCounter > 0)
        {
            IfElseCounter--;
            if(IfElseCounter == 0)
            {
                ifElseDeepList.push_back(IfCount);
                IfCount = 0;
                IfElseCounter = 0;
            }
        }

    }
}

void MainWindow::findLogicError(std::string str)
{
    std::regex regularWhileTrue("(while\\(true\\))");
    std::cmatch regWhileTrue;
    if(std::regex_search(str.c_str(),regWhileTrue,regularWhileTrue))
    {
        QMessageBox::information(this,"Error","Найдена потенциальная ошибка - бесконечный цикл while(true)");
    }
    std::regex regularWhileFalse("(while\\(false\\))");
    std::cmatch regWhileFalse;
    if(std::regex_search(str.c_str(),regWhileFalse,regularWhileFalse))
    {
        QMessageBox::information(this,"Error","Найдена потенциальная ошибка - не выполняется цикл while(false)");
    }
}


void MainWindow::reset()
{
    VARIABLE_COUNT = 0;
    ARRAY_COUNT = 0;
    CLASS_COUNT = 0;
    STRUCT_COUNT = 0;
    local = false;
    counter = 0;
    IfElseCounter = 0;
    IfCount = 0;
    varList.clear();
    funcList.clear();
    changeVarPos.clear();
    localVar.clear();
    funcOverload.clear();
    ifElseDeepList.clear();
}


void MainWindow::on_inputFile_clicked()
{
    ui->inputBox->clear();
        QFile file(QFileDialog::getOpenFileName(this,"Выберите файл", "C:\\","TXT File (*.txt);;CPP File (*.cpp)"));
            if (!file.open(QIODevice::ReadOnly)) {
                qWarning("Cannot open file for writing");
            }
        if(file.atEnd())
        {
            QMessageBox::warning(this,"Ошибка!","Выбранный файл пуст!");
            return;
        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
             QString str = in.readLine();
             ui->inputBox->append(str);
        }
        file.close();
}


void MainWindow::on_parse_clicked()
{
    ui->outputBox->clear();
    QString str = ui->inputBox->toPlainText();
    QStringList spl = str.split('\n');
    for(int i = 0; i < spl.size();i++)
    {
        std::string tmp = spl[i].toStdString();
        check_local(tmp);
        bool f = parseFunc(tmp, i);
        if(f)
            parseVariable(tmp,i);
        parseArray(tmp);
        parseClassNStruct(tmp);
        parseChangeVariable(tmp,i);
        ifElseDeep(tmp);
        findLogicError(tmp);
    }
    ui->outputBox->append("Количество переменных: " + QString::number(VARIABLE_COUNT));
    for(size_t i = 0; i < varList.size();i++)
    {
        ui->outputBox->append("     " + QString::fromStdString(varList[i]));
    }
    ui->outputBox->append("Количество массивов: " + QString::number(ARRAY_COUNT));
    ui->outputBox->append("Количество классов: " + QString::number(CLASS_COUNT));
    ui->outputBox->append("Количество структур: " + QString::number(STRUCT_COUNT));
    ui->outputBox->append("Количество прототипов функций: " + QString::number(funcList.size()));
    for(size_t i = 0; i < funcList.size();i++)
    {
        ui->outputBox->append("     " + QString::fromStdString(funcList[i]));
    }
    ui->outputBox->append("Координаты изменения переменных: ");
    for(size_t i = 0; i < changeVarPos.size();i++)
    {
        ui->outputBox->append("     Строка: " + QString::number(changeVarPos[i].first + 1)+ " Столбец: " + QString::number(changeVarPos[i].second + 1));
    }
    ui->outputBox->append("Координаты локальных переменных: ");
    for(size_t i = 0; i < localVar.size();i++)
    {
        ui->outputBox->append("     Строка: " + QString::number(localVar[i] + 1));
    }
    ui->outputBox->append("Количество перегруженных функций: " + QString::number(funcOverload.size()));
    ui->outputBox->append("Координаты: ");
    for(size_t i = 0; i < funcOverload.size();i++)
    {
        ui->outputBox->append("     Строка: " + QString::number(funcOverload[i] + 1));
    }
    ui->outputBox->append("Глубина if-else: ");
    for(size_t i = 0; i < ifElseDeepList.size();i++)
    {
        ui->outputBox->append(QString::number(i + 1)+ "-ое ветвление: " + QString::number(ifElseDeepList[i]));
    }
    reset();
}

