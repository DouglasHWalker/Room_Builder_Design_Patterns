#ifndef ROCKWALL_H
#define ROCKWALL_H
#include "core/dungeon/wall.h"

class RockWall : public Wall
{
public:
    RockWall() : Wall(){}
    ~RockWall() = default; // TODO: decontructor could already be implemented by Wall base class

    std::string description() override;
};

#endif // ROCKWALL_H
