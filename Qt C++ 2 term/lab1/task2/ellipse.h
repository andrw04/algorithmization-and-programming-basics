#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <shape.h>
#include <QPainter>
#include <QGraphicsObject>
#include <QColor>

class Ellipse : public Shape
{
    Q_OBJECT
public:
    Ellipse(int x,int y,int hor_r,int vert_r,QColor brush_color,QColor pen_color);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
    double SQUARE();
    double PERIMETR();
    void setScale(int hSc,int vSc);
public slots:
    void Scale();
protected:
    int horisontal_radius;
    int vertical_radius;
    int hScale;
    int vScale;
};

#endif // ELLIPSE_H
