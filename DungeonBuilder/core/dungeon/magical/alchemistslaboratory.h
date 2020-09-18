#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H
#include "core/dungeon/room.h"
namespace core::dungeon::magical {

class AlchemistsLaboratory : public Room
{
public:
    AlchemistsLaboratory(int id) : Room(id){}
    std::string description() override;
};

} // namespace core::dungeon::magical
#endif // ALCHEMISTSLABORATORY_H
