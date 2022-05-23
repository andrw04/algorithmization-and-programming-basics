#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <shape.h>
#include <QPainter>
#include <QColor>

class Rectangle : public Shape
{
    Q_OBJECT
public:
    Rectangle(int x,int y,int w,int h, QColor brush_color,QColor pen_color);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    double SQUARE();
    double PERIMETR();
    void setScale(int wSc,int hSc);
public slots:
    void Scale();
protected:
    int width;
    int height;
    int width_scale;
    int height_scale;
};

#endif // RECTANGLE_H
