#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H
#include "core/dungeon/room.h"
namespace core::dungeon::magical {
/**
 * @brief The AlchemistsLaboratory class is a type of Room.
 * It represents an entire room and its components (edges, item, creature) in the game @sa core::dungeon::Room
 */
class AlchemistsLaboratory : public Room
{
public:
    AlchemistsLaboratory(int id) : Room(id) {}
    std::string description() const override;

    friend std::ostream &operator <<(std::ostream &os, const AlchemistsLaboratory &room);
};

} // namespace core::dungeon::magical
#endif // ALCHEMISTSLABORATORY_H
