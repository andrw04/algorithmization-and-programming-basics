#include "triangle.h"

Triangle::Triangle(int x,int y,int b,int s,QColor brush_color,QColor pen_color) : Shape()
{
    pos_x = x;
    pos_y = y;
    base = b;
    side = s;
    bColor = brush_color;
    pColor = pen_color;
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon pol;
    painter->setPen(pColor);
    painter->setBrush(bColor);
    pol << QPoint(pos_x,pos_y + sqrt(pow(side,2) - pow(base / 2,2))) << QPoint(pos_x + base,pos_y + sqrt(pow(side,2) - pow(base / 2,2))) << QPoint(pos_x + base/2,pos_y);
    painter->drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Triangle::boundingRect() const
{
    return QRectF(pos_x,pos_y,base + 1,sqrt(pow(side,2) - pow(base / 2,2)) + 1);
}

double Triangle::SQUARE()
{
    return base * sqrt(pow(side,2) - pow(base / 2,2)) / 2;
}

double Triangle::PERIMETR()
{
    return 2 * side + base;
}

void Triangle::setScale(int bSc, int sSc)
{
    base_scale = bSc;
    side_scale = sSc;
}

void Triangle::Scale()
{
    if(base < base_scale)
    {
        base++;
    }
    else if(base > base_scale)
    {
        base--;
    }
    if(side < side_scale)
    {
        side++;
    }
    else if(side > side_scale)
    {
        side--;
    }
}
