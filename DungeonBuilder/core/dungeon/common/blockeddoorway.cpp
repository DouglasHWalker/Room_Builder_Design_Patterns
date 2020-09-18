#include "blockeddoorway.h"
namespace core::dungeon::common {

std::string BlockedDoorway::description(){
    return "a Blocked Doorway to another chamber";
}
char BlockedDoorway::displayCharacter(){
    return 'X';
}

} // namespace core::dungeon::common
