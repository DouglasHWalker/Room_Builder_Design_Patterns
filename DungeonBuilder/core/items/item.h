#ifndef ITEM_H
#define ITEM_H
#include <iostream>

class Item
{
public:
    Item(std::string name);
    virtual Item* clone() = 0;
    std::string name();
    char displayCharacter();

    friend std::ostream& operator <<(std::ostream& os, const Item& item);

protected:
    std::string _name;
    char _displayCharacter;
};

#endif // ITEM_H
