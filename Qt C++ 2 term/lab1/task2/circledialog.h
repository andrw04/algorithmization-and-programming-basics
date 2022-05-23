#ifndef CIRCLEDIALOG_H
#define CIRCLEDIALOG_H

#include <QDialog>
#include <QColor>
#include <QColorDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class CircleDialog;
}

class CircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CircleDialog(QWidget *parent = nullptr);
    ~CircleDialog();

private slots:
    void on_BrushColor_clicked();

    void on_PenColor_clicked();

    void on_buttonBox_accepted();

private:
    Ui::CircleDialog *ui;
signals:
    void sendInfo(int pos_x,int pos_y,int r,QColor brush_color,QColor pen_color);

};

#endif // CIRCLEDIALOG_H
