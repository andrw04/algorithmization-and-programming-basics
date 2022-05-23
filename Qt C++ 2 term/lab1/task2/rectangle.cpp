#include "rectangle.h"

Rectangle::Rectangle(int x,int y,int w,int h, QColor brush_color,QColor pen_color) : Shape()
{
    pos_x = x;
    pos_y = y;
    width = w;
    height = h;
    bColor = brush_color;
    pColor = pen_color;
}

  void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
  {
      painter->setPen(pColor);
      painter->setBrush(bColor);
      painter->drawRect(pos_x,pos_y,width,height);
      update();
      Q_UNUSED(option);
      Q_UNUSED(widget);
  }

  QRectF Rectangle::boundingRect() const
  {
      return QRectF(pos_x,pos_y, width + 1, height + 1);
  }

  double Rectangle::SQUARE()
  {
      return width * height;
  }

  double Rectangle::PERIMETR()
  {
      return 2 * (width + height);
  }

  void Rectangle::setScale(int wSc, int hSc)
  {
      width_scale = wSc;
      height_scale = hSc;
  }

  void Rectangle::Scale()
  {
      if(height < height_scale)
      {
          height++;
      }
      else if(height > height_scale)
      {
          height--;
      }
      if(width < width_scale)
      {
          width++;
      }
      else if(width > width_scale)
      {
          width--;
      }
  }
