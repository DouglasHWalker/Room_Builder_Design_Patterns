#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include "core/dungeon/doorway.h"
namespace core::dungeon::common {

class LockedDoor : public Doorway
{
public:
    std::string description() const override;
    char displayCharacter() const override;
};

} // namespace core::dungeon::common
#endif // LOCKEDDOOR_H
