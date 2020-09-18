#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H
#include "core/dungeon/room.h"
namespace core::dungeon::magical {

class EnchantedLibrary : public Room
{
public:
    EnchantedLibrary(int id) : Room(id) {}
    std::string description() const override;

    friend std::ostream &operator<<(std::ostream &os, const EnchantedLibrary &room);
};

} // namespace core::dungeon::magical
#endif // ENCHANTEDLIBRARY_H
