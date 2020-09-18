#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H
#include "core/dungeon/room.h"
namespace core::dungeon::basic {

class RockChamber : public Room
{
public:
    RockChamber(int id) : Room(id) {};
    std::string description() const override;

    friend std::ostream& operator<<(std::ostream& os, const RockChamber& chamber);
};

} // namespace core::dungeon::basic
#endif // ROCKCHAMBER_H
