#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "item.h"

class Consumable : public Item
{
public:
    Consumable(std::string name) : Item(name) {
        _displayCharacter = _DISPLAY_CHAR; // WARNING: is this instantiated at the correct level
        // TODO: intatiate values
    };
    Consumable *clone(){
        return new Consumable(*this);
    };
private:
    const char _DISPLAY_CHAR = 'C';
};

#endif // CONSUMABLE_H
