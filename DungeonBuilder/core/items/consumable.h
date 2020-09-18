#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "item.h"
namespace core::items {

class Consumable : public Item
{
public:
    Consumable(std::string name) : Item(name) {
        _displayCharacter = _DISPLAY_CHAR; // WARNING: is this instantiated at the correct level
    };
    std::unique_ptr<Item> clone() const{
        return std::make_unique<Consumable>(*this);
    };
private:
    const char _DISPLAY_CHAR = 'C';
};

} // namespace core::items
#endif // CONSUMABLE_H
