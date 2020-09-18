#include "alchemistslaboratory.h"
namespace core::dungeon::magical {

std::string AlchemistsLaboratory::description(){
    std::string description = "A musky laboratory filled with a myriad of glass chambers and beakers. "
                              "\nGreen liquid stains the floors. A smell of burnt hair pervades the airways. (Alchemists Laboratory)"
                              "\nTo the NORTH is " + edgeAt(Room::Direction::North)->description() +
                              "\nTo the SOUTH is " + edgeAt(Room::Direction::South)->description() +
                              "\nTo the EAST is " + edgeAt(Room::Direction::East)->description() +
                              "\nTo the WEST is " + edgeAt(Room::Direction::West)->description();
    description += _creature != nullptr ? "\nA " + _creature->name() + " is resting against a large couldren in the center of the laboratory." : "";
    description += _item != nullptr ? "\nYou can see a " + _item->name() + " on a nearby mixing table." : "";
    return description;
}

} // namespace core::dungeon::magical
