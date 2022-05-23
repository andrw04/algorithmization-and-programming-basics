#ifndef STAR_H
#define STAR_H
#include <QPainter>
#include <QColor>
#include <shape.h>
#include <QtMath>

class Star : public Shape
{
    Q_OBJECT
public:
    Star(int x, int y, int r, QColor brush_color,QColor pen_color);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
    double SQUARE();
    double PERIMETR();
    void setScale(int s);
public slots:
    void Scale();
private:
    int R;
    int R_scale;
};

#endif // STAR_H
