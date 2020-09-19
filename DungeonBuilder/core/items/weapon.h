#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
namespace core::items {
/**
 * @brief The Weapon class a type of Item @sa core::items::Item
 */
class Weapon : public Item
{
public:
    Weapon(const std::string &name): Item(name) {
        _displayCharacter = _DISPLAY_CHAR; // TODO: is this intasiated at the right level, could just use the super class 'L'
    };
    std::unique_ptr<Item> clone() const override{
        return std::make_unique<Weapon>(*this);
    };
private:
    const char _DISPLAY_CHAR = 'L';
};

} // namespace core::items
#endif // WEAPON_H
