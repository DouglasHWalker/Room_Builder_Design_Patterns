#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H
#include "core/dungeon/room.h"

class QuartzChamber : public Room
{
public:
    QuartzChamber(int id) : Room(id) {}
    std::string description();
};

#endif // QUARTZCHAMBER_H
