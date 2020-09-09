#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon : Item
{
public:
    Weapon();
    Weapoon clone();  // TODO: override, return deep copy of self
};

#endif // WEAPON_H
