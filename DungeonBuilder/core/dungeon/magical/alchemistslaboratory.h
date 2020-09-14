#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H
#include "core/dungeon/room.h"

class AlchemistsLaboratory : public Room
{
public:
    AlchemistsLaboratory(int id) : Room(id){}
    std::string description() override;
};

#endif // ALCHEMISTSLABORATORY_H
