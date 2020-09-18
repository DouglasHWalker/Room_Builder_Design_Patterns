#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H
#include "core/dungeon/room.h"
namespace core::dungeon::magical {

class AlchemistsLaboratory : public Room
{
public:
    AlchemistsLaboratory(int id) : Room(id){}
    std::string description() const override;

    friend std::ostream& operator<<(std::ostream& os, const AlchemistsLaboratory& room);
};

} // namespace core::dungeon::magical
#endif // ALCHEMISTSLABORATORY_H
