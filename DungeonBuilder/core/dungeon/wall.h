#ifndef WALL_H
#define WALL_H

#include "room.h"
namespace core::dungeon {

class Wall : public RoomEdge
{
public:
    Wall(Room::Direction direction): _direction{direction}{} // WARNING: does direction need to be passed in a better way
    virtual std::string description() const = 0;
    char displayCharacter() const;
    bool isPassage() const;

private:
    Room::Direction _direction;
};

} // namespace core::dungeon
#endif // WALL_H
