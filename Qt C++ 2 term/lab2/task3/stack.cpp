#include "stack.h"

Stack::Stack()
{
    index = 0;
}

void Stack::AddToStack(QChar value)
{
    array[++index] = value;
}

QChar Stack::GetFromStack()
{
    return array[index--];
}

QChar Stack::LastChar()
{
    return array[index];
}

int Stack::CharCount()
{
    return index;
}

int Stack::LastPriority()
{
    if(array[index] == '+' || array[index] == '-')
        return 2;
    else if(array[index] == '*' || array[index] == '/')
        return 3;
}

void Stack::Clear()
{
    index = 0;
}

