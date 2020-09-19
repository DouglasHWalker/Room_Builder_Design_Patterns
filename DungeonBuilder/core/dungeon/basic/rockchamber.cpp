#include <sstream>
#include "rockchamber.h"
namespace core::dungeon::basic {

std::string RockChamber::description() const {
    std::stringstream ss;
    // add each edge of the room to the output
    ss << "A dark, cold chamber. (Rock Chamber)"
       << "\nTo the NORTH is " << *edgeAt(Room::Direction::North)
       << "\nTo the SOUTH is " << *edgeAt(Room::Direction::South)
       << "\nTo the EAST is " << *edgeAt(Room::Direction::East)
       << "\nTo the WEST is " << *edgeAt(Room::Direction::West);
    // if creature exists, add to output
    if(_creature != nullptr) {
        ss << "\nYou catch some movement through the darkness. A " << *_creature << " has heard your approach.";
    }
    // if item exists, add to output
    if(_item != nullptr) {
        ss << "\nBlinded, you stumble on a " << *_item << " as you walk in.";
    }
    return ss.str();
}

std::ostream &operator <<(std::ostream &os, const RockChamber &chamber) {
    return os << chamber.description();
}

} // namespace core::dungeon::basic
