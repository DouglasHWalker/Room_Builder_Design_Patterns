#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H
#include "core/dungeon/room.h"
namespace core::dungeon::basic {
/**
 * @brief The RockChamber class is a type of Room.
 * It represents an entire room and its components (edges, item, creature) in the game
 * @sa core::dungeon::Room
 */
class RockChamber : public Room
{
public:
    RockChamber(int id) : Room(id) {};
    std::string description() const override;

    friend std::ostream &operator<<(std::ostream &os, const RockChamber &chamber);
};

} // namespace core::dungeon::basic
#endif // ROCKCHAMBER_H
