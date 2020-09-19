#ifndef WALL_H
#define WALL_H

#include "room.h"
namespace core::dungeon {
/**
 * @brief The Wall class is the base class for other wall types.
 * It is a type of roomEdge which cannot be traversed. @sa core::dungeon::RoomEdge
 */
class Wall : public RoomEdge
{
public:
    virtual std::string description() const override = 0;
    char displayCharacter() const override;
    bool isPassage() const override;

protected:
    Room::Direction _direction;
};

} // namespace core::dungeon
#endif // WALL_H
