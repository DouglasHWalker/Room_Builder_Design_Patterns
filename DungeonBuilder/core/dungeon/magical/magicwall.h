#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"

class MagicWall : public Wall
{
public:
    MagicWall(Room::Direction direction) : Wall(direction){}
    std::string description() override;
};

#endif // MAGICWALL_H
