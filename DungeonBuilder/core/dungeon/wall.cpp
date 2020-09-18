#include "wall.h"
namespace core::dungeon {

char Wall::displayCharacter(){
    switch (_direction) {
    case Room::Direction::North:
    case Room::Direction::South:
        return '-';
    case Room::Direction::East:
    case Room::Direction::West:
        return '|';
    }
}

bool Wall::isPassage(){
    return false;
}

} // namespace core::dungeon
