#include "truck.h"
#include <mainwindow.h>

Truck::Truck() : Rectangle()
{
    raise = true;
}

void Truck::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon1({QPoint(pos_x+140,-20),QPoint(pos_x + 220,-20),QPoint(pos_x + 220,-60),QPoint(pos_x + 180,-100),QPoint(pos_x + 140,-100)}); // кабина
    QPen pen(Qt::black,2,Qt::SolidLine);
    QPolygon polygon2({QPoint(pos_x+145,-60),QPoint(pos_x+215,-60),QPoint(pos_x+180,-95),QPoint(pos_x+145,-95)}); // стекло
    QPolygon polygon3({QPoint(pos_x,-80),QPoint(pos_x+40,-40),QPoint(pos_x+120,-40),QPoint(pos_x+140,-100),QPoint(pos_x+120,-100),
                      QPoint(pos_x+100,-80)}); // кузов опущен
    QPolygon polygon4({QPoint(pos_x,-40),QPoint(pos_x+60,-40),QPoint(pos_x+110,-100),QPoint(pos_x+90,-150),QPoint(pos_x+70,-140),QPoint(pos_x+65,-110)});
    painter->setBrush(Qt::darkGray);
    painter->drawRect(-400,0,1000,300);
    QPen pen1(Qt::white,10,Qt::DashDotLine);
    painter->setPen(pen1);
    painter->drawLine(-400,50,1000,50);
    painter->setPen(pen);
    painter->setBrush(Qt::gray);
    painter->drawRect(pos_x+20,pos_y-40,120,20);
    painter->setBrush(Qt::darkBlue);
    painter->drawPolygon(polygon1);
    painter->setBrush(Qt::black);
    painter->drawEllipse(pos_x+40,pos_y - 40,40,40);
    painter->drawEllipse(pos_x+160,pos_y-40,40,40);
    painter->setBrush(Qt::gray);
    painter->drawEllipse(pos_x+50,pos_y-30,20,20);
    painter->drawEllipse(pos_x+170,pos_y-30,20,20);
    painter->setBrush(Qt::lightGray);
    painter->drawPolygon(polygon2);
    painter->drawLine(pos_x+180,-60,pos_x+180,-95);
    painter->setBrush(QColor("#FFA500"));
    if(raise){
        painter->drawPolygon(polygon3);
    }
    else{
        painter->drawPolygon(polygon4);
    }
    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Truck::boundingRect() const
{
    return QRectF(pos_x-5,pos_y-150,230,151);
}

void Truck::raised()
{
    update();
}

