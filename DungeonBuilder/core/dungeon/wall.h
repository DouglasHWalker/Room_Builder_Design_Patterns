#ifndef WALL_H
#define WALL_H
#include "roomedge.h"

class Wall : RoomEdge
{
public:
    Wall() : RoomEdge(){}
    ~Wall() = default; // TODO: may not be required, could be done by base class

    virtual std::string description(); // TODO: does this require being virtual again? should it be an override
    char displayCharacter();
    bool isPassage();
};

#endif // WALL_H
