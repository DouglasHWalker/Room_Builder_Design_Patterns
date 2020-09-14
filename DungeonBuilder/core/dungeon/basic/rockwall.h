#ifndef ROCKWALL_H
#define ROCKWALL_H
#include "core/dungeon/wall.h"

class RockWall : public Wall
{
public:
    std::string description() override;
};

#endif // ROCKWALL_H
