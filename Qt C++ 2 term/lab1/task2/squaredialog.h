#ifndef SQUAREDIALOG_H
#define SQUAREDIALOG_H

#include <QDialog>
#include <QString>
#include <QColor>
#include <QMessageBox>
#include <QColorDialog>

namespace Ui {
class SquareDialog;
}

class SquareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SquareDialog(QWidget *parent = nullptr);
    ~SquareDialog();

private slots:
    void on_BrushColor_clicked();

    void on_PenColor_clicked();

    void on_buttonBox_accepted();

private:
    Ui::SquareDialog *ui;
signals:
    void sendInfo(int pos_x,int pos_y,int side_size,QColor brush_color,QColor pen_color);
};

#endif // SQUAREDIALOG_H
