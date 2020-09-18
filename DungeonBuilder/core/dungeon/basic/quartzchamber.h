#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H
#include "core/dungeon/room.h"
namespace core::dungeon::basic {

class QuartzChamber : public Room
{
public:
    QuartzChamber(int id) : Room(id) {};
    std::string description() const override;

    friend std::ostream &operator<<(std::ostream &os, const QuartzChamber &chamber);
};

} // namespace core::dungeon::basic
#endif // QUARTZCHAMBER_H
