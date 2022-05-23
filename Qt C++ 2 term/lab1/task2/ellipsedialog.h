#ifndef ELLIPSEDIALOG_H
#define ELLIPSEDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QMessageBox>
namespace Ui {
class EllipseDialog;
}

class EllipseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EllipseDialog(QWidget *parent = nullptr);
    ~EllipseDialog();

private slots:
    void on_BrushColor_clicked();

    void on_PenColor_clicked();

    void on_buttonBox_accepted();

private:
    Ui::EllipseDialog *ui;
signals:
    void sendInfo(int pos_x,int pos_y,int w,int h,QColor brush_color,QColor pen_color);
};

#endif // ELLIPSEDIALOG_H
