#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
namespace core::items {

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

} // namespace core::items
#endif // WEAPON_H
