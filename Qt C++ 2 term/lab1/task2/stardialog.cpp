#include "stardialog.h"
#include "ui_stardialog.h"

extern QColor brush_color;
extern QColor pen_color;
extern bool STAR_PARAMETRS;

StarDialog::StarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StarDialog)
{
    ui->setupUi(this);
}

StarDialog::~StarDialog()
{
    delete ui;
}

void StarDialog::on_BrushColor_clicked()
{
    brush_color = QColorDialog::getColor();
}


void StarDialog::on_PenColor_clicked()
{
    pen_color = QColorDialog::getColor();
}


void StarDialog::on_buttonBox_accepted()
{
    QString str = ui->position_X->text();
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
    str = ui->radius->text();
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
    emit sendInfo(ui->position_X->text().toInt(),ui->position_Y->text().toInt(),ui->radius->text().toInt(),brush_color,pen_color);
    STAR_PARAMETRS = true;
}

