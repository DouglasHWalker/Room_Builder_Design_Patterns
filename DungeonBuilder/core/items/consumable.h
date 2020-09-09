#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "item.h"

class Consumable : Item
{
public:
    Consumable();

    Consumable clone(); // TODO: override, return deep copy of self
};

#endif // CONSUMABLE_H
