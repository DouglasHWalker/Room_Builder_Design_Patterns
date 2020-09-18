#include "blockeddoorway.h"
namespace core::dungeon::common {

std::string BlockedDoorway::description() const {
    return "a Blocked Doorway to another chamber";
}
char BlockedDoorway::displayCharacter() const {
    return 'X';
}

} // namespace core::dungeon::common
