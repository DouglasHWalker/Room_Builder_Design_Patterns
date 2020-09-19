#include "wall.h"
namespace core::dungeon {

char Wall::displayCharacter() const {
    switch (_direction) {
        // if direction is north or south
    case Room::Direction::North:
    case Room::Direction::South:
        return '-';
        // if direction is East or West
    case Room::Direction::East:
    case Room::Direction::West:
        return '|';
    }
}

bool Wall::isPassage() const{
    return false;
}

std::ostream& operator << (std::ostream& os, const Wall& edge) {
    return os << edge.description();
}

} // namespace core::dungeon
