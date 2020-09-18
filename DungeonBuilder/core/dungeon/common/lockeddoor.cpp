#include "lockeddoor.h"
namespace core::dungeon::common {

std::string LockedDoor::description(){
    return "a Locked Door to another chamber.";
}
char LockedDoor::displayCharacter(){
    return '@';
}

} // namespace core::dungeon::common
