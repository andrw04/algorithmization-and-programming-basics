#include "hexagonedialog.h"
#include "ui_hexagonedialog.h"
extern bool HEXAGONE_PARAMETRS;
extern QColor brush_color;
extern QColor pen_color;

HexagoneDialog::HexagoneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HexagoneDialog)
{
    ui->setupUi(this);
}

HexagoneDialog::~HexagoneDialog()
{
    delete ui;
}

void HexagoneDialog::on_BrushColor_clicked()
{
    brush_color = QColorDialog::getColor();
}


void HexagoneDialog::on_PenColor_clicked()
{
    pen_color = QColorDialog::getColor();
}


void HexagoneDialog::on_buttonBox_accepted()
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
    str = ui->side->text();
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
    emit sendInfo(ui->position_X->text().toInt(),ui->position_Y->text().toInt(),ui->side->text().toInt(),brush_color,pen_color);
    HEXAGONE_PARAMETRS = true;
}

