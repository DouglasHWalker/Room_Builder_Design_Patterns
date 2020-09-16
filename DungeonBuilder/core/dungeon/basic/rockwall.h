#ifndef ROCKWALL_H
#define ROCKWALL_H
#include "core/dungeon/wall.h"

class RockWall : public Wall
{
public:
    RockWall(Room::Direction direction) : Wall(direction){}
    std::string description() override;
};

#endif // ROCKWALL_H
