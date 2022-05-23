#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsObject>
#include <QPainter>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>


class Shape : public QGraphicsObject
{
    Q_OBJECT
public:
    Shape();
    int angleInc();
    int angleDec();
public slots:
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
protected:
    int pos_x;
    int pos_y;
    QColor bColor;
    QColor pColor;
    int angle;
};

#endif // SHAPE_H
