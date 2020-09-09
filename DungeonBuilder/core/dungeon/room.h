#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include "core/items/item.h"
#include "core/creatures/abstractcreature.h"

class Room
{
public:
    Room(int id);

    std::string description();
    std::vector<std::string> display();
    int id();
    Item item();
    void setItem(Item newItem);
    AbstractCreature creature();
    void setCreature(AbstractCreature newCreature);

    enum class Direction : unsigned int { North, South, East, West };

private:
    int _id;
    Item _item;
    AbstractCreature _creature;
};

#endif // ROOM_H
