#include "findmaxkey.h"


FindMaxKey::FindMaxKey() : HashTable<QString>()
{

}

Stack<std::pair<int,QString>>* FindMaxKey::find_max()
{
    int max_key = 0;
    for(int i = 0; i < capacity;i++)
    {
        Stack<std::pair<int,QString>> *tmp = table[i];
        if(tmp != nullptr && i > max_key)
            max_key = i;
    }
    return table[max_key];
}
