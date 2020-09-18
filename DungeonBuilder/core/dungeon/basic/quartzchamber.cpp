#include "quartzchamber.h"
namespace core::dungeon::basic {

std::string QuartzChamber::description(){
    std::string description = "A chamber that gliters like a thousand stars in the torchlight. (Quartz Chamber)"
                              "\nTo the NORTH is " + edgeAt(Room::Direction::North)->description() +
                              "\nTo the SOUTH is " + edgeAt(Room::Direction::South)->description() +
                              "\nTo the EAST is " + edgeAt(Room::Direction::East)->description() +
                              "\nTo the WEST is " + edgeAt(Room::Direction::West)->description();
    description += _creature != nullptr ? "\nA " + _creature->name() + " is scratching at the walls of the chamber, curiously." : "";
    description += _item != nullptr ? "\nYou can see a " + _item->name() + " resting on a large stalatite in the center of the chamber." : "";
    return description;
}

} // namespace core::dungeon::basic
