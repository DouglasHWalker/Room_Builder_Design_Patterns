#ifndef ITEM_H
#define ITEM_H
#include <ostream>
#include <memory>

namespace core::items {
/**
 * @brief The Item class is the base class for all items in the game
 */
class Item
{
public:
    Item(std::string newName): _name{newName}{};
    virtual ~Item() = default;
    virtual std::unique_ptr<Item> clone() const = 0;
    std::string name() const;
    char displayCharacter() const;

    friend std::ostream& operator <<(std::ostream& os, const Item& item);

protected:
    /**
     * @brief _name of the item to use as the item description
     */
    std::string _name;
    /**
     * @brief _displayCharacter to display on the level map
     */
    char _displayCharacter;
};

} // namespace core::items
#endif // ITEM_H
