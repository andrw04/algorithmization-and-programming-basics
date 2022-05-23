#include "hexagone.h"
Hexagone::Hexagone(int x, int y, int s, QColor brush_color, QColor pen_color) : Shape()
{
    pos_x = x;
    pos_y = y;
    side = s;
    bColor = brush_color;
    pColor = pen_color;
}

void Hexagone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pColor);
    painter->setBrush(bColor);
    painter->drawLine(pos_x + side / sqrt(2),pos_y,pos_x + side + side /sqrt(2),pos_y);
    painter->drawLine(pos_x + side + side /sqrt(2),pos_y,pos_x + side + 2 * side / sqrt(2),pos_y + side / sqrt(2));
    painter->drawLine(pos_x + side + 2 * side / sqrt(2),pos_y + side / sqrt(2),pos_x + side + 2 * side / sqrt(2),pos_y + side / sqrt(2) + side);
    painter->drawLine(pos_x + side + 2 * side / sqrt(2),pos_y + side / sqrt(2) + side,pos_x + side + side /sqrt(2),pos_y + 2 * side / sqrt(2) + side);
    painter->drawLine(pos_x + side / sqrt(2),pos_y+ side + sqrt(2) * side,pos_x + side + side /sqrt(2),pos_y+ side + sqrt(2) * side);
    painter->drawLine(pos_x + side / sqrt(2),pos_y+ side + sqrt(2) * side,pos_x,pos_y + side + side / sqrt(2));
    painter->drawLine(pos_x,pos_y + side + side / sqrt(2),pos_x,pos_y + side / sqrt(2));
    painter->drawLine(pos_x,pos_y + side / sqrt(2),pos_x + side / sqrt(2),pos_y);
    update();
}

QRectF Hexagone::boundingRect() const
{
    return QRectF(pos_x,pos_y,3 * side,3 * side);
}

double Hexagone::SQUARE()
{
    return 3 * sqrt(3) * pow(side,2) / 2;
}

double Hexagone::PERIMETR()
{
    return 6 * side;
}

void Hexagone::setScale(int s)
{
    side_scale = s;
}

void Hexagone::Scale()
{
    if(side < side_scale)
    {
        side++;
    }
    else if(side > side_scale)
    {
        side--;
    }
    update();
}
