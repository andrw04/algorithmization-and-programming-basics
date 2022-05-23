#include "doublestack.h"

DoubleStack::DoubleStack()
{
    index = 0;
}

void DoubleStack::AddToStack(double value)
{
    array[++index] = value;
}

double DoubleStack::GetFromStack()
{
    return array[index--];
}

int DoubleStack::CharCount()
{
    return index;
}
