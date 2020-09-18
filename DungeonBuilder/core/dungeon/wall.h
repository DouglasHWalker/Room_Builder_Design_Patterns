#ifndef WALL_H
#define WALL_H

#include "room.h"
namespace core::dungeon {

class Wall : public RoomEdge
{
public:
    virtual std::string description() const = 0;
    char displayCharacter() const;
    bool isPassage() const;

protected:
    Room::Direction _direction;
};

} // namespace core::dungeon
#endif // WALL_H
