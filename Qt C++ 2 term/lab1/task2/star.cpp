#include "star.h"
Star::Star(int x, int y, int r, QColor brush_color,QColor pen_color)
{
    pos_x = x;
    pos_y = y;
    R = r;
    bColor = brush_color;
    pColor = pen_color;
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pColor);
    painter->setBrush(bColor);
    painter->translate(pos_x + 2*R,pos_y);
    painter->rotate(144);
    painter->translate(pos_x + R,pos_y);
    painter->drawLine(pos_x,pos_y,pos_x + 2*R,pos_y);
    painter->translate(pos_x + 2*R,pos_y);
    painter->rotate(144);
    painter->drawLine(pos_x,pos_y,pos_x + 2*R,pos_y);
    painter->translate(pos_x + 2*R,pos_y);
    painter->rotate(144);
    painter->drawLine(pos_x,pos_y,pos_x + 2*R,pos_y);
    painter->translate(pos_x + 2*R,pos_y);
    painter->rotate(144);
    painter->drawLine(pos_x,pos_y,pos_x + 2*R,pos_y);
    painter->translate(pos_x + 2*R,pos_y);
    painter->rotate(144);
    painter->drawLine(pos_x,pos_y,pos_x + 2*R,pos_y);
    painter->translate(pos_x + 2*R,pos_y);
    painter->rotate(144);
    update();

}

QRectF Star::boundingRect() const
{
    return QRectF(pos_x-R,pos_y-R,3*R+1,3*R+1);
}

double Star::SQUARE()
{
    return 5 / 2 * pow(R,2) * sin(2 * 3.14 / 5) - 5 * pow(R,2)*(5-pow(5,1/2))/4 * tan(3.14 / 5) / 2;
}

double Star::PERIMETR()
{
    return (5 / 2 * pow(R,2) * sin(2 * 3.14 / 5) - 5 * pow(R,2)*(5-pow(5,1/2))/4 * tan(3.14 / 5) / 2) / 3.33;
}

void Star::setScale(int s)
{
    R_scale = s;
}

void Star::Scale()
{
    if(R < R_scale)
    {
        R++;
    }
    else if(R > R_scale)
    {
        R--;
    }
    update();
}
