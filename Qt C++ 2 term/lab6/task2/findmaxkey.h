#ifndef FINDMAXKEY_H
#define FINDMAXKEY_H
#include <hashtable.h>
#include <QString>

class FindMaxKey : public HashTable<QString>
{
public:
    FindMaxKey();
    Stack<std::pair<int, QString> > *find_max();
};

#endif // FINDMAXKEY_H
