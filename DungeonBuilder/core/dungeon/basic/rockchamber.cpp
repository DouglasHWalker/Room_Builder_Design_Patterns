#include "rockchamber.h"

std::string RockChamber::description(){
    std::string description = "A dark, cold chamber. (Rock Chamber)"
           "\nTo the NORTH is " + edgeAt(Room::Direction::North)->description() +
           "\nTo the SOUTH is " + edgeAt(Room::Direction::South)->description() +
           "\nTo the EAST is " + edgeAt(Room::Direction::East)->description() +
           "\nTo the WEST is " + edgeAt(Room::Direction::West)->description();
    description += _item != nullptr ? "\nBlinded, your foot kicks a " + _item->name() + " as you walk in. It slides to the center of the chamber" : "";
    description += _creature != nullptr ? "\nYou catch some movement through the darkness. A " + _creature->name() + " has heard your approach." : "";
    return description;
}
