#include "wall.h"
namespace core::dungeon {

char Wall::displayCharacter() const {
    switch (_direction) {
    case Room::Direction::North:
    case Room::Direction::South:
        return '-';
    case Room::Direction::East:
    case Room::Direction::West:
        return '|';
    }
}

bool Wall::isPassage() const{
    return false;
}

std::ostream& operator << (std::ostream& os, const Wall& edge){
    return os << edge.description();
}

} // namespace core::dungeon
