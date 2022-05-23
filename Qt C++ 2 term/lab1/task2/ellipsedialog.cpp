#include "ellipsedialog.h"
#include "ui_ellipsedialog.h"

extern QColor pen_color;
extern QColor brush_color;
extern bool ELLIPSE_PARAMETRS;

EllipseDialog::EllipseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EllipseDialog)
{
    ui->setupUi(this);
}

EllipseDialog::~EllipseDialog()
{
    delete ui;
}

void EllipseDialog::on_BrushColor_clicked()
{
    brush_color = QColorDialog::getColor();
}


void EllipseDialog::on_PenColor_clicked()
{
    pen_color = QColorDialog::getColor();
}


void EllipseDialog::on_buttonBox_accepted()
{
    QString str = ui->position_X->text();
    for(int i = 0; i < str.size();i++)
    {
        if(str[i] == '-' && i == 0)
            continue;
        if(str[i] < '0' || str[i] > '9')
        {
            QMessageBox::warning(this,"Ошибка!","Введите корректные данные");
            return;
        }
    }
    if(str.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка!","Введите корректные данные");
        return;
    }
    str.clear();
    str = ui-> position_Y->text();
    for(int i = 0; i < str.size();i++)
    {
        if(str[i] == '-' && i == 0 && str.size() > 1)
            continue;
        if(str[i] < '0' || str[i] > '9')
        {
            QMessageBox::warning(this,"Ошибка!","Введите корректные данные");
            return;
        }
    }
    if(str.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка!","Введите корректные данные");
        return;
    }
    str.clear();
    str = ui->width->text();
    for(int i = 0; i < str.size();i++)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            QMessageBox::warning(this,"Ошибка!","Введите корректные данные");
            return;
        }
    }
    if(str.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка!","Введите корректные данные");
        return;
    }
    str.clear();
    str = ui->height->text();
    for(int i = 0;i < str.size();i++)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            QMessageBox::warning(this,"Ошибка!","Введите корректные данные");
            return;
        }
    }
    if(str.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка!","Введите корректные данные");
        return;
    }
    emit sendInfo(ui->position_X->text().toInt(),ui->position_Y->text().toInt(),ui->width->text().toInt(),ui->height->text().toInt(),brush_color,pen_color);
    ELLIPSE_PARAMETRS = true;
}

