#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <weak_ptr.h>
#include <weak_ptr.cpp>
#include <shared_ptr.h>
#include <shared_ptr.cpp>

class Item
{
public:
    Item();
    Item(std::string n);
    friend bool partnerUp(SHARED_PTR<Item> &h1, SHARED_PTR<Item> &h2);
    SHARED_PTR<Item> getPartner();
private:
    std::string name;
    WEAK_PTR<Item> object;

};

#endif // ITEM_H
