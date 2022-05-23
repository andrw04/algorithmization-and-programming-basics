#include "item.h"

Item::Item()
{

}

Item::Item(std::string n)
{
    name = n;
}

SHARED_PTR<Item> Item::getPartner()
{
    return object.lock();
}

bool partnerUp(SHARED_PTR<Item> &h1, SHARED_PTR<Item> &h2)
{
    if (!h1 || !h2)
        return false;

    h1->object = h2;
    h2->object = h1;

    return true;
}
