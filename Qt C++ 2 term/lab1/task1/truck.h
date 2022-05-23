#ifndef TRUCK_H
#define TRUCK_H
#include "rectangle.h"
#include <QPainter>

class Truck : public Rectangle
{
public:
    Truck();
    bool raise;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
public slots:
    void raised() override;
};

#endif // TRUCK_H
