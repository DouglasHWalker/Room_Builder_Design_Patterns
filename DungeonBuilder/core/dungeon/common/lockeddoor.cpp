#include "lockeddoor.h"
namespace core::dungeon::common {

std::string LockedDoor::description() const {
    return "a Locked Door to another chamber.";
}
char LockedDoor::displayCharacter() const {
    return '@';
}

} // namespace core::dungeon::common
