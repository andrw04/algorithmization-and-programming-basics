#include "circle.h"

Circle::Circle(int x,int y,int r,QColor brush_color,QColor pen_color) : Shape()
{
    pos_x = x;
    pos_y = y;
    radius = r;
    bColor = brush_color;
    pColor = pen_color;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pColor);
    painter->setBrush(bColor);
    painter->drawEllipse(pos_x,pos_y,2*radius,2*radius);
    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Circle::boundingRect() const
{
    return QRectF(pos_x,pos_y,2*radius + 1,2*radius + 1);
}

double Circle::SQUARE()
{
    return 3.14 * pow(radius,2);
}

double Circle::PERIMETR()
{
    return 2 * 3.14 * radius;
}

void Circle::setScale(int s)
{
    scale_size = s;
}

void Circle::Scale()
{
    if(radius < scale_size)
    {
        radius++;
    }
    else if(radius > scale_size)
    {
        radius--;
    }
}
