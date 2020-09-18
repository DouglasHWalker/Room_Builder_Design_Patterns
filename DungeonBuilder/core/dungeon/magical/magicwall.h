#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"
namespace core::dungeon::magical {

class MagicWall : public Wall
{
public:
    MagicWall(const Room::Direction &direction){
        _direction = direction;
    }
    std::string description() const override;
};

} // namespace core::dungeon::magical
#endif // MAGICWALL_H
