#include "ellipse.h"

Ellipse::Ellipse(int x,int y,int hor_r,int vert_r,QColor brush_color,QColor pen_color) : Shape()
{
    pos_x = x;
    pos_y = y;
    horisontal_radius = hor_r;
    vertical_radius = vert_r;
    bColor = brush_color;
    pColor = pen_color;
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->translate(pos_x + dx,pos_y + dy);
    //painter->rotate(angle);
    painter->setPen(pColor);
    painter->setBrush(bColor);
    //painter->translate(dx,dy);
    //painter->rotate(angle);
    painter->drawEllipse(pos_x,pos_y,2 * horisontal_radius,2 * vertical_radius);
    //painter->translate(dx,dy);
    //ainter->rotate(angle);
    //painter->translate(pos_x - dx,pos_y -dy);
    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Ellipse::boundingRect() const
{
     return QRectF(pos_x,pos_y,2 * horisontal_radius + 1,2 * vertical_radius + 1);
}

double Ellipse::SQUARE()
{
    return 3.14 * horisontal_radius * vertical_radius;
}

double Ellipse::PERIMETR()
{
    return 4 * (3.14 * horisontal_radius * vertical_radius + pow(horisontal_radius - vertical_radius,2))/(horisontal_radius + vertical_radius);
}


void Ellipse::setScale(int hSc,int vSc)
{
    hScale = hSc;
    vScale = vSc;
}


void Ellipse::Scale()
{
    if(vertical_radius < vScale)
    {
        vertical_radius++;
    }
    else if(vertical_radius > vScale)
    {
        vertical_radius--;
    }
    if(horisontal_radius < hScale)
    {
        horisontal_radius++;
    }
    else if(horisontal_radius > hScale)
    {
        horisontal_radius--;
    }
}
