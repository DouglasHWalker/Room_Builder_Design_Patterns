#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <memory>

class Item
{
public:
    Item(std::string name): _name{name}{}
    virtual std::unique_ptr<Item> clone() = 0;
    std::string name();
    char displayCharacter();

    friend std::ostream& operator <<(std::ostream& os, const Item& item);

protected:
    std::string _name;
    char _displayCharacter;
};

#endif // ITEM_H
