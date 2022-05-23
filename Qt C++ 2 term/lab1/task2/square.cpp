#include "square.h"

Square::Square(int x, int y, int side_size, QColor brush_color, QColor pen_color) : Shape()
{
    pos_x = x;
    pos_y = y;
    side = side_size;
    bColor = brush_color;
    pColor = pen_color;

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pColor);
    painter->setBrush(bColor);
    painter->drawRect(pos_x,pos_y,side,side);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Square::boundingRect() const
{
    return QRectF(pos_x,pos_y,side,side);
}

double Square::SQUARE()
{
    return side * side;
}

double Square::PERIMETR()
{
    return 4 * side;
}

void Square::setScale(int s)
{
        side_scale = s;
}

void Square::Scale()
{
    if(side < side_scale)
    {
        side++;
    }
    else if(side > side_scale)
    {
        side--;
    }
}

