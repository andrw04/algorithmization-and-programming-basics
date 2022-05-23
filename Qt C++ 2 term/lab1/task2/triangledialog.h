#ifndef TRIANGLEDIALOG_H
#define TRIANGLEDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QMessageBox>

namespace Ui {
class TriangleDialog;
}

class TriangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TriangleDialog(QWidget *parent = nullptr);
    ~TriangleDialog();

private slots:
    void on_BrushColor_clicked();

    void on_PenColor_clicked();

    void on_buttonBox_accepted();

private:
    Ui::TriangleDialog *ui;
signals:
    void sendInfo(int pos_x,int pos_y,int base_size,int side_size,QColor brush_color,QColor pen_color);
};

#endif // TRIANGLEDIALOG_H
