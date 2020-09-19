#ifndef ROCKWALL_H
#define ROCKWALL_H
#include "core/dungeon/wall.h"
namespace core::dungeon::basic {
/**
 * @brief The RockWall class is a type of Wall.
 * It is a type of RoomEdge which cannot be traversed.
 * @sa core::dungeon::Wall @sa core::dungeon::RoomEdge
 */
class RockWall : public Wall
{
public:
    RockWall(const Room::Direction &newDirection) {
        _direction = newDirection;
    }
    std::string description() const override;
};

} // namespace core::dungeon::basic
#endif // ROCKWALL_H
