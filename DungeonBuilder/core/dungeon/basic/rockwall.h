#ifndef ROCKWALL_H
#define ROCKWALL_H
#include "core/dungeon/wall.h"
namespace core::dungeon::basic {
/**
 * @brief The RockWall class is a type of wall (@sa core::dungeon::Wall).
 * It is a type of roomEdge (@sa core::dungeon::RoomEdge) which cannot be traversed.
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
