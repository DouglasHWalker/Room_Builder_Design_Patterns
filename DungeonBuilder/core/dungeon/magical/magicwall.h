#ifndef MAGICWALL_H
#define MAGICWALL_H
#include "core/dungeon/wall.h"
namespace core::dungeon::magical {
/**
 * @brief The MagicWall class is a type of Wall
 * It is a type of RoomEdge which cannot be traversed.
 * @sa core::dungeon::RoomEdge @sa core::dungeon::Wall
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
