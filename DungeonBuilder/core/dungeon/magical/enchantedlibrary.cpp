#include "enchantedlibrary.h"
#include <sstream>
namespace core::dungeon::magical {

std::string EnchantedLibrary::description() const {   
    std::stringstream ss;
    // add each edge of the room to output
    ss << "A vast library brimming with thousands of heavy tomes. "
       << "\n\"The Gang of Four by D. Pattern\" can be seen on the nearest shelf. (Enchanted Library)"
       << "\nTo the NORTH is " << *edgeAt(Room::Direction::North)
       << "\nTo the SOUTH is " << *edgeAt(Room::Direction::South)
       << "\nTo the EAST is " << *edgeAt(Room::Direction::East)
       << "\nTo the WEST is " << *edgeAt(Room::Direction::West);
    // if item exits, add item to output
    if(_item != nullptr) {
        ss << "\nA " << *_item << " rests on a desk nearby.";
    }
    // if creature exists, add creature to output
    if(_creature != nullptr) {
        ss << "\nA " << *_creature << " is snoring loudly amongst the volumes.";
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const EnchantedLibrary& room) {
    return os << room.description();
}

} // namespace core::dungeon::magical
