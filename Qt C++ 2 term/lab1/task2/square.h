#ifndef SQUARE_H
#define SQUARE_H
#include <QPainter>
#include <QColor>
#include <shape.h>

class Square : public Shape
{
    Q_OBJECT
public:
    Square(int x,int y,int side_size,QColor brush_color,QColor pen_color);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
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

#endif // SQUARE_H
