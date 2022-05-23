#include "mainwindow.h"
#include "ui_mainwindow.h"

int Max = 1;
int ExprCount = 1;
int varCount = 1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    operatorStr = new Stack;
    expressions = new QString[ExprCount];
    doubleStack = new DoubleStack;
    values = new QString[varCount];

}

MainWindow::~MainWindow()
{
    delete ui;
}

double* addVar(double *obj,double str) // массив выражений
{
    if(varCount == 1)
    {
        obj[0] = str;
    }
    else
    {
        double *tmp = new double[varCount];
        for(int i = 0;i < varCount - 1;i++)
        {
            tmp[i] = obj[i];
        }
        delete[] obj;
        obj = tmp;
        obj[varCount - 1] = str;
    }
    varCount++;
    return obj;
}


QString MainWindow::ConvertToOPW(QString InputStr) // функция перевода из инфиксной формы в постфиксную
{
    QString outputStr;
    outputStr.clear();
    operatorStr->Clear();
    for(int i = 0; i < InputStr.size();i++)
    {
        if(InputStr[i] >= 'a' && InputStr[i] <= 'z')
        {
            outputStr.append(InputStr[i]);
            continue;
        }
        else if(InputStr[i] == '(')
        {
            operatorStr->AddToStack(InputStr[i]);
            continue;
        }
        else if(InputStr[i] == ')')
        {
            while(operatorStr->LastChar() != '(')
                outputStr.append(operatorStr->GetFromStack());
            if(operatorStr->LastChar() == '(')
                operatorStr->GetFromStack();
            continue;
        }
        else if(InputStr[i] == '+' || InputStr[i] == '-' || InputStr[i] == '*' || InputStr[i] == '/')
        {
            int priority = 1;
            if(InputStr[i] == '+' || InputStr[i] == '-')
                priority = 2;
            else if(InputStr[i] == '*' || InputStr[i] == '/')
                priority = 3;
            //if(InputStr[i] == '-' || InputStr[i] == '/')
             while(priority <= operatorStr->LastPriority())
             {
                 outputStr.append(operatorStr->GetFromStack());
             }
            /*if(InputStr[i] == '+' || InputStr[i] == '*')
            {
                while(priority < operatorStr->LastPriority())
                {
                    outputStr.append(operatorStr->GetFromStack());
                }
            }*/
            operatorStr->AddToStack(InputStr[i]);
            continue;
        }
    }
    while(operatorStr->CharCount() >= 0)
        outputStr.append(operatorStr->GetFromStack());
    return outputStr;
}


double MainWindow::GetResultOPW(QString InputStr,double a,double b,double c,double d,double e)
{
    for(int i = 0; i < InputStr.size();i++)
    {
        if(InputStr[i] == 'a')
        {
            doubleStack->AddToStack(a);
            continue;
        }
        if(InputStr[i] == 'b')
        {
            doubleStack->AddToStack(b);
            continue;
        }
        if(InputStr[i] == 'c')
        {
            doubleStack->AddToStack(c);
            continue;
        }
        if(InputStr[i] == 'd')
        {
            doubleStack->AddToStack(d);
            continue;
        }
        if(InputStr[i] == 'e')
        {
            doubleStack->AddToStack(e);
            continue;
        }
        if(InputStr[i] == '+')
        {
            double right = doubleStack->GetFromStack();
            double left = doubleStack->GetFromStack();
            doubleStack->AddToStack(left + right);
            continue;
        }
        if(InputStr[i] == '-')
        {
            double right = doubleStack->GetFromStack();
            double left = doubleStack->GetFromStack();
            doubleStack->AddToStack(left - right);
            continue;
        }
        if(InputStr[i] == '*')
        {
            double right = doubleStack->GetFromStack();
            double left = doubleStack->GetFromStack();
            doubleStack->AddToStack(left * right);
            continue;
        }
        if(InputStr[i] == '/')
        {
            double right = doubleStack->GetFromStack();
            double left = doubleStack->GetFromStack();
            doubleStack->AddToStack(left / right);
            continue;
        }
    }
    double result = doubleStack->GetFromStack();
    return result;
}


void MainWindow::on_pushButton_3_clicked()
{
    QString str = ui->OldExpr->toPlainText();
    QStringList strList=str.split('\n');
    for(int i = 0; i < strList.size();i++)
    {
        strList[i] = ConvertToOPW(strList[i]);
    }
    for(int i = 0;i < strList.size();i++)
    {
        ui->NewExpr->append(strList[i]);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString str = ui->NewExpr->toPlainText();
    QStringList strList = str.split('\n');
    QString valA = ui->valA->toPlainText();
    QString valB = ui->valB->toPlainText();
    QString valC = ui->valC->toPlainText();
    QString valD = ui->valD->toPlainText();
    QString valE = ui->valE->toPlainText();
    QStringList valAList = valA.split('\n');
    QStringList valBList = valB.split('\n');
    QStringList valCList = valC.split('\n');
    QStringList valDList = valD.split('\n');
    QStringList valEList = valE.split('\n');
    for(int i = 0; i < strList.size();i++)
    {
        double a = valAList[i].toDouble();
        double b = valBList[i].toDouble();
        double c = valCList[i].toDouble();
        double d = valDList[i].toDouble();
        double e = valEList[i].toDouble();
        ui->ResultOPW->append(QString::number(GetResultOPW(strList[i],a,b,c,d,e)));
        switch(i)
        {
        case 0:
            ui->Result->append(QString::number(a/(b-c)*(d+e)));
            break;
        case 1:
            ui->Result->append(QString::number(a-(b+c*d)/e));
            break;
        case 2:
            ui->Result->append(QString::number(a*(b-c+d)/e));
            break;
        case 3:
            ui->Result->append(QString::number(a*(b-c)/(d+e)));
            break;
        case 4:
            ui->Result->append(QString::number((a+(b/c-d))*e));
            break;
        case 5:
            ui->Result->append(QString::number(a-(b/c*(d+e))));
            break;
        case 6:
            ui->Result->append(QString::number(a/(b+c-d*e)));
            break;
        case 7:
            ui->Result->append(QString::number((a+b*c)/(d-e)));
            break;
        case 8:
            ui->Result->append(QString::number((a+b)*(c-d)/e));
            break;
        case 9:
            ui->Result->append(QString::number(a/b-((c+d)*e)));
            break;
        case 10:
            ui->Result->append(QString::number((a+b)*(c-d)/e));
            break;
        case 11:
            ui->Result->append(QString::number(a/(b*(c+d))-e));
            break;
        case 12:
            ui->Result->append(QString::number(a*(b+c)/(d-e)));
            break;
        case 13:
            ui->Result->append(QString::number((a-b)/(c+d)*e));
            break;
        case 14:
            ui->Result->append(QString::number((a*(b-c)/(d+e))));
            break;
        }

    }
}

