#ifndef ROOM_H
#define ROOM_H
#include "core/dungeon/roomedge.h"
#include "core/items/item.h"
#include "core/creatures/abstractcreature.h"
namespace core::dungeon {

class Room
{
public:
    Room(int id);
    ~Room() = default;
    enum class Direction : unsigned int { North, South, East, West }; // WARNING: enum overload operator to reverse direction
    // not operator negates the direction so that north points south, east points west and vise versa
    friend Room::Direction operator ! (Room::Direction& r1){
        switch(r1){
        case Room::Direction::North: return Room::Direction::South;
        case Room::Direction::South: return Room::Direction::North;
        case Room::Direction::East: return Room::Direction::West;
        case Room::Direction::West: return Room::Direction::East;
        }
    }
    virtual std::string description() = 0;
    std::array<std::string, 5> display();
    int id();
    std::unique_ptr<core::items::Item> item();
    void setItem(std::unique_ptr<core::items::Item> newItem);
    std::unique_ptr<core::creatures::AbstractCreature> creature();
    void setCreature(std::unique_ptr<core::creatures::AbstractCreature> newCreature);
    void setEdge(std::shared_ptr<RoomEdge> edge, Room::Direction direction);
    std::shared_ptr<RoomEdge> edgeAt(Room::Direction direction);
protected:
    int _id;
    std::unique_ptr<core::items::Item> _item;
    std::unique_ptr<core::creatures::AbstractCreature> _creature;
    std::array<std::shared_ptr<RoomEdge>, 4> _edges;
};

} // namespace core::dungeon
#endif // ROOM_H
