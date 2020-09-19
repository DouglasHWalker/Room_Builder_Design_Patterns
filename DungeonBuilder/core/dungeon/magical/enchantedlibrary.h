#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H
#include "core/dungeon/room.h"
namespace core::dungeon::magical {
/**
 * @brief The EnchantedLibrary class is a type of room (@sa core::dungeon::Room).
 * It represents an entire room and its components (edges, item, creature) in the game
 */
class EnchantedLibrary : public Room
{
public:
    EnchantedLibrary(int id) : Room(id) {}
    std::string description() const override;

    friend std::ostream &operator<<(std::ostream &os, const EnchantedLibrary &room);
};

} // namespace core::dungeon::magical
#endif // ENCHANTEDLIBRARY_H
