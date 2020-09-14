#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H
#include "core/dungeon/room.h"

class EnchantedLibrary : public Room
{
public:
    EnchantedLibrary(int id) : Room(id){}
    std::string description() override;
};

#endif // ENCHANTEDLIBRARY_H
