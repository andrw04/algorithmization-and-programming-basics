#include "stack.h"
#include <QVector>

stack::stack()
{

}

void stack::push(char ch)
{
    array[++index] = ch;
}

char stack::pop()
{
    return array[index--];
}
