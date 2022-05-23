#include "shape.h"

Shape::Shape() : QGraphicsObject()
{
    angle = 0;
}

int Shape::angleInc()
{
    return ++angle;
}

int Shape::angleDec()
{
    return --angle;
}

void Shape::MoveLeft()
{
        --pos_x;
    update();
}

void Shape::MoveUp()
{
        --pos_y;
    update();
}

void Shape::MoveDown()
{
        ++pos_y;
    update();
}

void Shape::MoveRight()
{
        ++pos_x;
    update();
}

