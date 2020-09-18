#include "opendoorway.h"
namespace core::dungeon::common {

std::string OpenDoorway::description(){
    return "an Open Doorway to another chamber";
}
char OpenDoorway::displayCharacter(){
    switch(_direction){
    case Room::Direction::North:
        return '^';
    case Room::Direction::South:
        return 'v';
    case Room::Direction::East:
        return '>';
    case Room::Direction::West:
        return '<';
    default:
        break;
    }
}

} // namespace core::dungeon::common
