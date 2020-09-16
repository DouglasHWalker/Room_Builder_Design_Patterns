#ifndef WALL_H
#define WALL_H
#include "room.h"
#include "roomedge.h"

class Wall : public RoomEdge
{
public:
    Wall(Room::Direction direction): _direction{direction}{}
    virtual std::string description() = 0; // TODO: does this require being virtual again? should it be an override
    char displayCharacter();
    bool isPassage();
private:
    Room::Direction _direction;
};

#endif // WALL_H
