#include "squaredialog.h"
#include "ui_squaredialog.h"

extern QColor brush_color;
extern QColor pen_color;
extern bool SQUARE_PARAMETRS;

SquareDialog::SquareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SquareDialog)
{
    ui->setupUi(this);
}

SquareDialog::~SquareDialog()
{
    delete ui;
}

void SquareDialog::on_BrushColor_clicked()
{
    brush_color = QColorDialog::getColor();
}


void SquareDialog::on_PenColor_clicked()
{
    pen_color = QColorDialog::getColor();
}


void SquareDialog::on_buttonBox_accepted()
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
    str = ui->SquareSide->text();
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
    emit sendInfo(ui->position_X->text().toInt(),ui->position_Y->text().toInt(),ui->SquareSide->text().toInt(),brush_color,pen_color);
    SQUARE_PARAMETRS = true;
}

