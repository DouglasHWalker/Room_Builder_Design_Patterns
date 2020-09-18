#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include "core/dungeon/doorway.h"
namespace core::dungeon::common {

class LockedDoor : public Doorway
{
public:    
    std::string description() override;
    char displayCharacter() override;
};

} // namespace core::dungeon::common
#endif // LOCKEDDOOR_H
