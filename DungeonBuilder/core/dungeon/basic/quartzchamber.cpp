#include <sstream>
#include "quartzchamber.h"
namespace core::dungeon::basic {

std::string QuartzChamber::description() const {
    std::stringstream ss;
    // add each edge of the room to the output
    ss << "A chamber that gliters like a thousand stars in the torchlight. (Quartz Chamber)"
       << "\nTo the NORTH is " << *edgeAt(Room::Direction::North)
       << "\nTo the SOUTH is " << *edgeAt(Room::Direction::South)
       << "\nTo the EAST is " << *edgeAt(Room::Direction::East)
       << "\nTo the WEST is " << *edgeAt(Room::Direction::West);
    ss << "\nA silhouette moves across the twinkling surfaces...";
    // if item exists, add to output
    if(_item != nullptr) {
        ss << "\nYour foot brushes past a " << *_item << " as you step forward for a closer look.";
        // if no creature exists, add explanatory text
        if(_creature == nullptr) {
            ss << "\nIt must have been your imagination, nothing else is here...";
        }
    }
    // if creature exists, add to output
    if(_creature != nullptr) {
        ss << "\nWhat is that? You lean forward, arching your back."
           << "\nIt's a" << (_creature->isBoss() ? "n " : " ") << *_creature << "!";
    }
    return ss.str();
}

std::ostream &operator <<(std::ostream &os, const QuartzChamber &chamber) {
    return os << chamber.description();
}

} // namespace core::dungeon::basic
