#include "rectangle.h"

Rectangle::Rectangle()
{
    pos_x = 0;
    pos_y = 0;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->setPen(Qt::gray);
    painter->drawRect(pos_x,pos_y,50,300);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(pos_x,pos_y,300,50);
}

void Rectangle::move_left()
{
    if(pos_x <= -550)
        pos_x = 500;
    else
        --pos_x;
    update();
}

void Rectangle::move_right()
{
    if(pos_x >= 550)
        pos_x = -500;
    else
        ++pos_x;
    update();
}

void Rectangle::raised()
{

}
