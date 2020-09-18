#ifndef ROCKWALL_H
#define ROCKWALL_H
#include "core/dungeon/wall.h"
namespace core::dungeon::basic {

class RockWall : public Wall
{
public:
    RockWall(const Room::Direction &direction){
        _direction = direction;
    }
    std::string description() const override;
};

} // namespace core::dungeon::basic
#endif // ROCKWALL_H
