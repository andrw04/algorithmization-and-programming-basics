#ifndef STACK_H
#define STACK_H
#include <QVector>

class stack
{
public:
    stack();
    char array[1000];
    int index = 0;
    void push(char ch);
    char pop();
};

#endif // STACK_H
