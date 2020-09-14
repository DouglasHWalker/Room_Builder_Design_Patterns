#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon : public Item
{
public:
    Weapon(std::string name) : Item(name){}; // TODO: instatiate values
    Weapon *clone(){
        return new Weapon(*this);
    };
};

#endif // WEAPON_H
