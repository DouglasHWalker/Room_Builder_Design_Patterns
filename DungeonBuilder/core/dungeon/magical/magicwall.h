#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"

class MagicWall : public Wall
{
public:
    std::string description() override;
};

#endif // MAGICWALL_H
