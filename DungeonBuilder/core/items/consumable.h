#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "item.h"
namespace core::items {
/**
 * @brief The Consumable class a type of Item (@sa core::items::Item) which can be described to the user/player
 */
class Consumable : public Item
{
public:
    Consumable(const std::string &name): Item(name) {
        _displayCharacter = _DISPLAY_CHAR; // WARNING: is this instantiated at the correct level
    };
    std::unique_ptr<Item> clone() const override{
        return std::make_unique<Consumable>(*this);
    };
private:
    const char _DISPLAY_CHAR = 'L';
};

} // namespace core::items
#endif // CONSUMABLE_H
