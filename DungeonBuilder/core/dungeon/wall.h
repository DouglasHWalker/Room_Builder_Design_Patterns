#ifndef WALL_H
#define WALL_H

#include "room.h"
namespace core::dungeon {

class Wall : public RoomEdge
{
public:
    Wall(Room::Direction direction): _direction{direction}{} // WARNING: does direction need to be passed in a better way
    virtual std::string description() = 0;
    char displayCharacter();
    bool isPassage();
private:
    Room::Direction _direction;
};

} // namespace core::dungeon
#endif // WALL_H
