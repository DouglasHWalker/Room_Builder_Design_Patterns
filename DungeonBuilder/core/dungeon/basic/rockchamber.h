#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H
#include "core/dungeon/room.h"

class RockChamber : public Room
{
public:
    RockChamber(int id) : Room(id) {}
    std::string description();
};

#endif // ROCKCHAMBER_H
