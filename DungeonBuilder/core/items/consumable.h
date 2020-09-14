#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "item.h"

class Consumable : public Item
{
public:
    Consumable(std::string name) : Item(name) {}; // TODO: intatiate values
    Consumable *clone(){
        return new Consumable(*this);
    };
};

#endif // CONSUMABLE_H
