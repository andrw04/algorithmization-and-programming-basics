#ifndef STACK_H
#define STACK_H
#include <QChar>

class Stack
{
public:
    Stack();
    void AddToStack(QChar value);
    QChar GetFromStack();
    QChar LastChar();
    int CharCount();
    int LastPriority();
    void Clear();
private:
    int index;
    QChar array[3000];
};

#endif // STACK_H
