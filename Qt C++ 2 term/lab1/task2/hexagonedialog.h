#ifndef HEXAGONEDIALOG_H
#define HEXAGONEDIALOG_H

#include <QDialog>
#include <QString>
#include <QColor>
#include <QMessageBox>
#include <QColorDialog>
#include <QObject>
#include <QGraphicsScene>

namespace Ui {
class HexagoneDialog;
}

class HexagoneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HexagoneDialog(QWidget *parent = nullptr);
    ~HexagoneDialog();

private:
    Ui::HexagoneDialog *ui;
signals:
    void sendInfo(int pos_x,int pos_y,int side_size,QColor brush_color,QColor pen_color);
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();
};

#endif // HEXAGONEDIALOG_H
