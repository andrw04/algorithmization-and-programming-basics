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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_2;
    QPushButton *show;
    QPushButton *find;
    QTreeWidget *treeWidget;
    QPushButton *reset;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *individual_task;
    QTableWidget *tableWidget;
    QPushButton *from_array;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(400, 10, 391, 111));
        groupBox->setAutoFillBackground(true);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 80, 301, 28));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(67, 40, 191, 29));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 40, 101, 29));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 51, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 51, 20));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 120, 391, 471));
        groupBox_2->setAutoFillBackground(true);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(100);

        gridLayout->addWidget(spinBox_2, 3, 1, 1, 1);

        show = new QPushButton(groupBox_2);
        show->setObjectName(QString::fromUtf8("show"));

        gridLayout->addWidget(show, 7, 0, 1, 4);

        find = new QPushButton(groupBox_2);
        find->setObjectName(QString::fromUtf8("find"));

        gridLayout->addWidget(find, 3, 0, 1, 1);

        treeWidget = new QTreeWidget(groupBox_2);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        gridLayout->addWidget(treeWidget, 6, 0, 1, 4);

        reset = new QPushButton(groupBox_2);
        reset->setObjectName(QString::fromUtf8("reset"));

        gridLayout->addWidget(reset, 3, 2, 1, 1);

        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMaximum(100);

        gridLayout->addWidget(spinBox_3, 3, 3, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 4);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 4);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 4);

        individual_task = new QPushButton(groupBox_2);
        individual_task->setObjectName(QString::fromUtf8("individual_task"));

        gridLayout->addWidget(individual_task, 5, 0, 1, 4);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 26)
            tableWidget->setRowCount(26);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(6, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(7, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(8, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(9, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(10, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(10, 1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(11, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(11, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(12, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(12, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(13, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(13, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(14, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(14, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(15, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(15, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(16, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(16, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(17, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(17, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(18, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(18, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(19, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(19, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(20, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(20, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(21, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(21, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setItem(22, 0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setItem(22, 1, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setItem(23, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setItem(23, 1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setItem(24, 0, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget->setItem(24, 1, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget->setItem(25, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget->setItem(25, 1, __qtablewidgetitem53);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 380, 531));
        tableWidget->setFont(font);
        tableWidget->setAutoFillBackground(true);
        tableWidget->setRowCount(26);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(0);
        tableWidget->horizontalHeader()->setDefaultSectionSize(189);
        from_array = new QPushButton(centralwidget);
        from_array->setObjectName(QString::fromUtf8("from_array"));
        from_array->setGeometry(QRect(10, 550, 363, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "task1", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\320\265 \321\201 \320\264\320\265\321\200\320\265\320\262\320\276\320\274", nullptr));
        show->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        find->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Tree:", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\321\213\320\271 \320\276\320\261\321\205\320\276\320\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\271 \320\276\320\261\321\205\320\276\320\264", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\277\320\276\321\200\321\217\320\264\320\272\320\265 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\217 \320\272\320\273\321\216\321\207\320\265\320\271", nullptr));
        individual_task->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200. \320\272\320\273\321\216\321\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(0, 0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(1, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(1, 1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(2, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(2, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(3, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(3, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(4, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(4, 1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(5, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(5, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(6, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "21", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(6, 1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(7, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(7, 1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(8, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(8, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(9, 0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(9, 1);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "J", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(10, 0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(10, 1);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(11, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(11, 1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(12, 0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(12, 1);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(13, 0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "23", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(13, 1);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(14, 0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(14, 1);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "O", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(15, 0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(15, 1);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(16, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "21", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(16, 1);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "Q", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(17, 0);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(17, 1);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(18, 0);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(18, 1);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(19, 0);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(19, 1);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(20, 0);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(20, 1);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(21, 0);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(21, 1);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(22, 0);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->item(22, 1);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->item(23, 0);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->item(23, 1);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->item(24, 0);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->item(24, 1);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget->item(25, 0);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->item(25, 1);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        from_array->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\267 \320\274\320\260\321\201\321\201\320\270\320\262\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
