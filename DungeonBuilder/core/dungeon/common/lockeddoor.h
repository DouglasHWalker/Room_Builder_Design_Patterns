#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include "core/dungeon/doorway.h"
namespace core::dungeon::common {
/**
 * @brief The LockedDoor class a type of Doorway which needs to be unlocked before it can be traversed
 * A type of traversable RoomEdge
 */
class LockedDoor : public Doorway
{
public:
    std::string description() const override;
    char displayCharacter() const override;
};

} // namespace core::dungeon::common
#endif // LOCKEDDOOR_H
