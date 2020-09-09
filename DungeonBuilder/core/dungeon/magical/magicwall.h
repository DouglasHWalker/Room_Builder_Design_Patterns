#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"

class MagicWall : Wall
{
public:
    MagicWall();

    std::string description();
    char displayCharacter();
    bool isPassage();
};

#endif // MAGICWALL_H
