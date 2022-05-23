#include "mainwindow.h"
#include "ui_mainwindow.h"

UNIQUE_PTR<Item> u(new Item());
UNIQUE_PTR<Item> p;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    v.push_back(SHARED_PTR<Item>(new Item()));
    qDebug() << "Main Shared_ptr obj adress : " << v[0].get() << "\n";
    qDebug() << "Main Unique_ptr obj adress : " << u.get() << "\n";
    upd();
}


void MainWindow::upd()
{
    ui->lineEdit->setText(QString::number(v[0].use_count()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddShared_clicked()
{
    v.push_back(SHARED_PTR<Item>(v[0]));
    auto t = &v[v.size()-1];
    qDebug() << "Shared_ptr at " << t << " was created!";
    upd();
}


void MainWindow::on_CheckUnique_clicked()
{
     if(v[0].unique())
         QMessageBox::information(this,"Information","Уникален");
     else
         QMessageBox::information(this,"Information","Не уникален");
}


void MainWindow::on_RemoveShared_clicked()
{
    auto t = v.size()-1;
    qDebug() << "Shared_ptr at " << &v[t] << " was deleted!";
    v.pop_back();
    if(v.size())
        upd();
    else{
        QMessageBox::information(this,"Последствия","Последний shared_ptr был удален, также как и управляемый объект");
        this->close();
    }
}


void MainWindow::on_ShowSharedList_clicked()
{
    qDebug() << "List for shared_ptrs:\n";
    for(int i = 0; i < v.size(); i++){
        qDebug() << i << ") own adress: " << &v[i] << ", points on adress: " << v[i].get();
    }
    qDebug() << "\n";
}


void MainWindow::on_CreateCircle_clicked()
{
    auto p1 = SHARED_PTR<Item>(new Item());
    auto p2 = SHARED_PTR<Item>(new Item());
    partnerUp(p1,p2);
    auto partner = p1->getPartner();
    qDebug() << &partner << "is parnter " << &p2;
    qDebug() << "p1 points to p2";
    qDebug() << "p2 points to p1";

}


void MainWindow::on_addUnique_clicked()
{
    u = UNIQUE_PTR<Item>(new Item());
    qDebug() << "own adress: " << &u << ", points on adress: " << u.get();

}


void MainWindow::on_removeUnique_clicked()
{
    p = UNIQUE_PTR<Item>();
    qDebug() << "own adress: " << &p << ", points on adress: " << p.get();
}

