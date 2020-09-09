#ifndef WALL_H
#define WALL_H
#include "roomedge.h"

class Wall : RoomEdge
{
public:
    Wall();

    std::string description();
    char displayCharacter();
    bool isPassage();
};

#endif // WALL_H
