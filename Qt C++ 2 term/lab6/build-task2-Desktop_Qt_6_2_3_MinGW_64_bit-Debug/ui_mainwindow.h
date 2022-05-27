/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QSpinBox *spinBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *find;
    QPushButton *clear;
    QPushButton *add;
    QPushButton *reset;
    QPushButton *print;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QPushButton *random;
    QPushButton *Print_t2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 411, 581));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(430, 10, 361, 251));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 50, 48, 29));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 50, 131, 28));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 31, 20));
        find = new QPushButton(groupBox);
        find->setObjectName(QString::fromUtf8("find"));
        find->setGeometry(QRect(10, 130, 341, 29));
        clear = new QPushButton(groupBox);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(10, 210, 341, 29));
        add = new QPushButton(groupBox);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(210, 50, 141, 29));
        reset = new QPushButton(groupBox);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(10, 90, 341, 29));
        reset->setCheckable(false);
        print = new QPushButton(groupBox);
        print->setObjectName(QString::fromUtf8("print"));
        print->setGeometry(QRect(10, 170, 341, 29));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 30, 111, 20));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(430, 270, 361, 321));
        random = new QPushButton(groupBox_2);
        random->setObjectName(QString::fromUtf8("random"));
        random->setGeometry(QRect(10, 30, 341, 29));
        Print_t2 = new QPushButton(groupBox_2);
        Print_t2->setObjectName(QString::fromUtf8("Print_t2"));
        Print_t2->setGeometry(QRect(10, 70, 341, 29));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 110, 341, 29));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        find->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        print->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Individual task", nullptr));
        random->setText(QCoreApplication::translate("MainWindow", "Random Keys", nullptr));
        Print_t2->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Find max key", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
