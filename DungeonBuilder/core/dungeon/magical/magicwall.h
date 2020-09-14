#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"

class MagicWall : public Wall
{
public:
    MagicWall() : Wall(){}
    ~MagicWall() = default; // TODO: decontructor could already be implemented by Wall base class

    std::string description() override;
};

#endif // MAGICWALL_H
