#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon : public Item
{
public:
    Weapon(std::string name) : Item(name){
        _displayCharacter = _DISPLAY_CHAR;
        // TODO: instatiate values
    };
    std::unique_ptr<Item> clone(){
        return std::make_unique<Weapon>(*this);
    };
private:
    const char _DISPLAY_CHAR = 'W';
};

#endif // WEAPON_H
