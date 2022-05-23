#include "circledialog.h"
#include "ui_circledialog.h"

QColor pen_color;
QColor brush_color;
extern bool CIRCLE_PARAMETRS;

CircleDialog::CircleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CircleDialog)
{
    ui->setupUi(this);

}

CircleDialog::~CircleDialog()
{
    delete ui;
}

void CircleDialog::on_BrushColor_clicked()
{
    brush_color = QColorDialog::getColor();
}


void CircleDialog::on_PenColor_clicked()
{
    pen_color = QColorDialog::getColor();
}


void CircleDialog::on_buttonBox_accepted()
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
    CIRCLE_PARAMETRS = true;
}

