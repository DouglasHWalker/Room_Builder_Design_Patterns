#ifndef ITEM_H
#define ITEM_H
#include <ostream>
#include <memory>

namespace core::items {

class Item
{
public:
    Item(std::string name): _name{name}{};
    virtual ~Item() = default;
    virtual std::unique_ptr<Item> clone() const = 0;
    std::string name() const;
    char displayCharacter() const;

    friend std::ostream& operator <<(std::ostream& os, const Item& item);

protected:
    std::string _name;
    char _displayCharacter;
};

} // namespace core::items
#endif // ITEM_H
