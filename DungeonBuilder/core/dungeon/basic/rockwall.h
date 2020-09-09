#ifndef ROCKWALL_H
#define ROCKWALL_H
#include "core/dungeon/wall.h"

class RockWall : Wall
{
public:
    RockWall();

    std::string description();
    char displayCharacter();
    bool isPassage();
};

#endif // ROCKWALL_H
