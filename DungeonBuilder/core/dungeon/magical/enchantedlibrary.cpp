#include "enchantedlibrary.h"
namespace core::dungeon::magical {

std::string EnchantedLibrary::description(){
    std::string description = "A vast library brimming with thousands of heavy tomes. "
                              "\n\"The Gang of Four by D. Pattern\" can be seen on the nearest shelf. (Enchanted Library)"
                              "\nTo the NORTH is " + edgeAt(Room::Direction::North)->description() +
                              "\nTo the SOUTH is " + edgeAt(Room::Direction::South)->description() +
                              "\nTo the EAST is " + edgeAt(Room::Direction::East)->description() +
                              "\nTo the WEST is " + edgeAt(Room::Direction::West)->description();
    description += _item != nullptr ? "\nA " + _item->name() + " rests on a desk nearby." : "";
    description += _creature != nullptr ? "\nA " + _creature->name() + " is snoring loudly between the volumes." : "";
    return description;
}

} // namespace core::dungeon::magical
