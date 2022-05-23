#ifndef HEXAGONE_H
#define HEXAGONE_H
#include <shape.h>
#include <QPainter>
#include <QGraphicsItem>
#include <QColor>

class Hexagone : public Shape
{
    Q_OBJECT
public:
    Hexagone(int x,int y,int r,QColor brush_color,QColor pen_color);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
    double SQUARE();
    double PERIMETR();
    void setScale(int s);
public slots:
    void Scale();
protected:
    int side;
    int side_scale;
};

#endif // HEXAGONE_H
