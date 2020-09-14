#ifndef WALL_H
#define WALL_H
#include "roomedge.h"

class Wall : public RoomEdge
{
public:
    virtual std::string description() = 0; // TODO: does this require being virtual again? should it be an override
    char displayCharacter();
    bool isPassage();
};

#endif // WALL_H
