#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"
namespace core::dungeon::magical {

class MagicWall : public Wall
{
public:
    MagicWall(Room::Direction direction) : Wall(direction){}
    std::string description() const override;
};

} // namespace core::dungeon::magical
#endif // MAGICWALL_H
