#include <sstream>
#include "alchemistslaboratory.h"
namespace core::dungeon::magical {

std::string AlchemistsLaboratory::description() const {
    std::stringstream ss;
    // add every edge of room to output
    ss << "A musky laboratory filled with a myriad of glass chambers and beakers. "
       << "\nGreen liquid stains the floors. A smell of burnt hair pervades the airways. (Alchemists Laboratory)"
       << "\nTo the NORTH is " << *edgeAt(Room::Direction::North)
       << "\nTo the SOUTH is " << *edgeAt(Room::Direction::South)
       << "\nTo the EAST is " << *edgeAt(Room::Direction::East)
       << "\nTo the WEST is " << *edgeAt(Room::Direction::West);
    // if creature exists, add to output
    if(_creature != nullptr) {
        ss << "\nA " << *_creature << " is resting against a large couldren in the center of the laboratory.";
    }
    // if item exists add to output
    if(_item != nullptr) {
        ss << "\nYou can see a " << *_item << " on a nearby mixing table.";
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const AlchemistsLaboratory& room) {
    return os << room.description();
}

} // namespace core::dungeon::magical
