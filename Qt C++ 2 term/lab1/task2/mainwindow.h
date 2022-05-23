#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QColor>
#include <circle.h>
#include <QVector>
#include <QTimer>
#include <circledialog.h>
#include <rectangle.h>
#include <rectangledialog.h>
#include <ellipse.h>
#include <ellipsedialog.h>
#include <square.h>
#include <squaredialog.h>
#include <triangle.h>
#include <triangledialog.h>
#include <QInputDialog>
#include <star.h>
#include <stardialog.h>
#include <hexagone.h>
#include <hexagonedialog.h>
#include <canva.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_FigureParametrs_clicked();
    void getCircleInfo(int pos_x,int pos_y,int r,QColor brush_color,QColor pen_color);
    void getRectangleInfo(int pos_x,int pos_y,int w,int h,QColor brush_color,QColor pen_color);
    void getEllipseInfo(int pos_x,int pos_y,int horisontal,int vertical,QColor brush_color,QColor pen_color);
    void getSquareInfo(int pos_x,int pos_y,int side_size,QColor brush_color,QColor pen_color);
    void getTriangleInfo(int pos_x,int pos_y,int base_size,int side_size,QColor brush_color,QColor pen_color);
    void getStarInfo(int pos_x, int pos_y, int r, QColor brush_color, QColor pen_color);
    void getHexagoneInfo(int pos_x, int pos_y, int side_size, QColor brush_color, QColor pen_color);
    void Lrotate();
    void Rrotate();
private slots:
    void on_addFigure_clicked();

    //void on_moveLeft_clicked();

    void on_moveRight_clicked();

    void on_SquareSelected_clicked();

    void on_PerimetrSelected_clicked();


    void on_moveLeft_clicked();

    void on_moveUp_clicked();

    void on_moveDown_clicked();

    void on_Scale_clicked();

    void on_rotL_clicked();

    void on_DxDy_clicked();

    void on_rotR_clicked();

    void on_myFigure_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Circle*> objects;
    QGraphicsScene *scene;
    Circle *circle;
    CircleDialog *cDialog;
    Rectangle *rectangle;
    RectangleDialog *rDialog;
    Ellipse *ellipse;
    EllipseDialog *eDialog;
    Square *square;
    SquareDialog *sDialog;
    Triangle *triangle;
    TriangleDialog *tDialog;
    Star *star;
    StarDialog *stDialog;
    Hexagone *hexagone;
    HexagoneDialog *hDialog;
    Canva *canva;
    QVector<Circle*> circles;
    QVector<Rectangle*> rectangles;
    QVector<Ellipse*> ellipses;
    QVector<Square*> squares;
    QVector<Triangle*> triangles;
    QVector<Star*> stars;
    QVector<Hexagone*> hexagons;
    QTimer *timer;
    QTimer *rotatingTimer;

};
#endif // MAINWINDOW_H
