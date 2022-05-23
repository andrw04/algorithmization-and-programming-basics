#ifndef VIEWIMAGE_H
#define VIEWIMAGE_H
#include <queue.h>
#include <QImage>

class ViewImage : public Queue<QImage>
{
public:
    ViewImage(){}
    ViewImage(QImage value) : Queue<QImage>(value){}
    void push_back(QImage value){
        if(size == 0)
        {
            first = std::shared_ptr<Queue<QImage>>(new Queue<QImage>(value));
            last = first;
        }
        else
        {
            last->next = std::shared_ptr<Queue<QImage>>(new Queue<QImage>(value));
            std::shared_ptr<Queue<QImage>> tmp = last;
            last = last->next;
            last->prev = tmp;
        }

        // делаем кольцо
        last->next = first;
        first->prev = last;

        size++;
    }
    void move_left()
    {
        first = first->next;
        last = last->next;
    }
    void move_right()
    {
        first = first->prev;
        last = last->prev;
    }

};

#endif // VIEWIMAGE_H
