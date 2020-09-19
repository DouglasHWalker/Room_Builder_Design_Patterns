#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H
#include "core/dungeon/room.h"
namespace core::dungeon::basic {
/**
 * @brief The QuartzChamber class is a type of Room.
 * It represents an entire room and its components (edges, item, creature) in the game
 * @sa core::dungeon::Room
 */
class QuartzChamber : public Room
{
public:
    QuartzChamber(int id) : Room(id) {};
    std::string description() const override;

    friend std::ostream &operator<<(std::ostream &os, const QuartzChamber &chamber);
};

} // namespace core::dungeon::basic
#endif // QUARTZCHAMBER_H
