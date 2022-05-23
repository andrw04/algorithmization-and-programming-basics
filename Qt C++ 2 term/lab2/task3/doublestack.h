#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H


class DoubleStack
{
public:
    DoubleStack();
    void AddToStack(double value);
    double GetFromStack();
    void Clear();
    int CharCount();
private:
    int index;
    double array[3000];
};

#endif // DOUBLESTACK_H
