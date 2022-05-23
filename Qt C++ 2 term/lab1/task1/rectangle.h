#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QPainter>
#include <QGraphicsObject>
#include <QGraphicsItemGroup>

class Rectangle : public QGraphicsObject
{
    Q_OBJECT
public:
    Rectangle();
    int pos_x;
    int pos_y;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
public slots:
    void move_left();
    void move_right();
    virtual void raised();
};

#endif // RECTANGLE_H
