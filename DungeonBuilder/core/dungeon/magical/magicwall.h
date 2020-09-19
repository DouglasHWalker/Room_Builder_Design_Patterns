#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"
namespace core::dungeon::magical {
/**
 * @brief The MagicWall class is a type of wall (@sa core::dungeon::Wall).
 * It is a type of roomEdge (@sa core::dungeon::RoomEdge) which cannot be traversed.
 */
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
