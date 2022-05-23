#ifndef RECTANGLEDIALOG_H
#define RECTANGLEDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QMessageBox>

namespace Ui {
class RectangleDialog;
}

class RectangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RectangleDialog(QWidget *parent = nullptr);
    ~RectangleDialog();

private slots:
    void on_BrushColor_clicked();

    void on_PenColor_clicked();

    void on_buttonBox_accepted();

private:
    Ui::RectangleDialog *ui;
signals:
    void sendInfo(int pos_x,int pos_y,int w,int h,QColor brush_color,QColor pen_color);
};

#endif // RECTANGLEDIALOG_H
