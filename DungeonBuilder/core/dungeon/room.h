#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include "core/dungeon/roomedge.h"
#include "core/items/item.h"
#include "core/creatures/abstractcreature.h"

class Room
{
public:
    Room(int id);
    ~Room() = default;

    enum class Direction : unsigned int { North, South, East, West }; // WARNING: enum overload operator to reverse direction

    virtual std::string description();
    std::vector<std::string> display();
    int id();
    std::unique_ptr<Item> item();
    void setItem(std::unique_ptr<Item>& newItem);
    std::unique_ptr<AbstractCreature> creature();
    void setCreature(std::unique_ptr<AbstractCreature> newCreature);
    void setEdge(std::shared_ptr<RoomEdge> edge, Room::Direction direction);
    std::shared_ptr<RoomEdge> edgeAt(Room::Direction direction);

private:
    int _id;
    std::unique_ptr<Item> _item;
    std::unique_ptr<AbstractCreature> _creature;
    std::array<std::shared_ptr<RoomEdge>, 4> _edges;
};

#endif // ROOM_H
