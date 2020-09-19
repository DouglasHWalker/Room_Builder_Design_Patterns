#ifndef ROOM_H
#define ROOM_H
#include "core/dungeon/roomedge.h"
#include "core/items/item.h"
#include "core/creatures/abstractcreature.h"
namespace core::dungeon {
/**
 * @brief The Room class represents an entire room and its components (edges, item, creature) in the game
 */
class Room
{
public:
    Room(int id);
    ~Room() = default;
    enum class Direction : unsigned int { North, South, East, West };
    //
    /**
     * @brief operator ! negates direction so that north points south, east points west and vise versa
     * @param r1 The direction to negate
     * @return South if r1 is north, east if r1 is west and vice-versa W->E S->N
     */
    friend Room::Direction operator! (const Room::Direction& r1) {
        switch(r1) {
        case Room::Direction::North: return Room::Direction::South;
        case Room::Direction::South: return Room::Direction::North;
        case Room::Direction::East: return Room::Direction::West;
        case Room::Direction::West: return Room::Direction::East;
        }
    }
    /**
     * @brief description of the room
     * @return the description of the room and all its components
     */
    virtual std::string description() const = 0;
    /**
     * @brief display the map of a single room
     * @return a list of strings representing the map of a single room
     */
    std::array<std::string, 5> display() const;
    int id() const;
    std::unique_ptr<core::items::Item> item(); // non-const pointer transfer owenership
    void setItem(const std::unique_ptr<core::items::Item> newItem); // non-const pointer transfer owenership
    std::unique_ptr<core::creatures::AbstractCreature> creature();  // non-const pointer transfer owenership
    void setCreature(const std::unique_ptr<core::creatures::AbstractCreature> newCreature); // non-const pointer transfer owenership
    void setEdge(const std::shared_ptr<RoomEdge> edge, const Room::Direction &direction);
    std::shared_ptr<RoomEdge> edgeAt(const Room::Direction &direction) const;
protected:
    /**
     * @brief _id: room identification
     */
    int _id;
    /**
     * @brief _item the item contained in the room, can be null
     */
    std::unique_ptr<core::items::Item> _item;
    /**
     * @brief _creature the creature contained in the room, can be null
     */
    std::unique_ptr<core::creatures::AbstractCreature> _creature;
    /**
     * @brief _edges a list of the rooms edges
     */
    std::array<std::shared_ptr<RoomEdge>, 4> _edges;
};

} // namespace core::dungeon
#endif // ROOM_H
