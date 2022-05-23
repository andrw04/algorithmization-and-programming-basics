#ifndef STARDIALOG_H
#define STARDIALOG_H

#include <QDialog>
#include <QString>
#include <QColor>
#include <QMessageBox>
#include <QColorDialog>

namespace Ui {
class StarDialog;
}

class StarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StarDialog(QWidget *parent = nullptr);
    ~StarDialog();

private:
    Ui::StarDialog *ui;
signals:
    void sendInfo(int pos_x,int pos_y,int r,QColor brush_color,QColor pen_color);
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();
};

#endif // STARDIALOG_H
