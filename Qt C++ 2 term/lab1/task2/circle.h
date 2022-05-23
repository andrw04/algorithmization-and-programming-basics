#ifndef CIRCLE_H
#define CIRCLE_H
#include <shape.h>
#include <QPainter>
#include <QGraphicsObject>
#include <QColor>

class Circle : public Shape
{
    Q_OBJECT
public:
    Circle(int x,int y,int r,QColor brush_color,QColor pen_color);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
    double SQUARE();
    double PERIMETR();
    void setScale(int s);
public slots:
    void Scale();
protected:
    int radius;
    int scale_size;
};

#endif // CIRCLE_H
