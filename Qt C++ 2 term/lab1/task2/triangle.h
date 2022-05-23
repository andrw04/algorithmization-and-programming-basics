#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QPainter>
#include <QColor>
#include <shape.h>
#include <QPolygon>
#include <QPen>

class Triangle : public Shape
{
    Q_OBJECT
public:
    Triangle(int x,int y,int b,int s,QColor brush_color,QColor pen_color);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
    double SQUARE();
    double PERIMETR();
    void setScale(int bSc,int sSc);
public slots:
    void Scale();
protected:
    int base;
    int side;
    int base_scale;
    int side_scale;
};

#endif // TRIANGLE_H
