#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"
namespace core::dungeon::magical {

class MagicWall : public Wall
{
public:
    MagicWall(const Room::Direction &newDirection) {
        _direction = newDirection;
    }
    std::string description() const override;
};

} // namespace core::dungeon::magical
#endif // MAGICWALL_H
