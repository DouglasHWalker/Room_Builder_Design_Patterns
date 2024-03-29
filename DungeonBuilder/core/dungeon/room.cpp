#include "room.h"
namespace core::dungeon {

using core::creatures::AbstractCreature;
using core::items::Item;

Room::Room(int id) : _id{id} {
    // intialise _edges array to size of 4
    _edges = std::array<std::shared_ptr<RoomEdge>, 4>();
}

std::array<std::string, 6> Room::display() const{
    std::array<std::string, 6> output = std::array<std::string, 6>();
    // Create North Row string
    std::string northRow{"+----"};
    // northern RoodEdge
    northRow += edgeAt(Direction::North)->displayCharacter();
    northRow += "----+  ";
    // Create Middle Row
    std::string middleRow{};
    // Western RoomEdge
    middleRow += edgeAt(Direction::West)->displayCharacter();
    middleRow += "   ";
    // if room does not have creature
    if(_creature == nullptr) {
        middleRow += "  ";
    }
    else {
        middleRow += _creature->displayCharacter();
        // if creature is boss add asterix
        middleRow += _creature->isBoss() ? '*' : ' ';
    }
    // if room has an item add item character
    middleRow += _item != nullptr ? _item->displayCharacter() : ' ';
    middleRow +=  "   ";
    // East RoomEdge
    middleRow += edgeAt(Direction::East)->displayCharacter();
    // if middle row has passage, add to passage spcaer to output
    middleRow += edgeAt(Direction::East)->isPassage() ? "--" : "  ";
    // Create South Row
    std::string southRow{"+----"};
    // South RoomEdge
    southRow += edgeAt(Direction::South)->displayCharacter();
    southRow += "----+  ";
    // Create Spacer row
    std::string spacerRow = edgeAt(Room::Direction::South)->isPassage() ? "     |       " : "             ";
    // Create Blank Row
    std::string blankRow{"|         |  "};

    // Add strings to output
    output[0] = northRow;
    output[1] = blankRow;
    output[2] = middleRow;
    output[3] = blankRow;
    output[4] = southRow;
    output[5] = spacerRow;

    return output;
}

int Room::id() const{
    return _id;
}

std::unique_ptr<Item> Room::item() {
    return std::move(_item);
}

void Room::setItem(std::unique_ptr<Item> newItem) {
    _item = std::move(newItem);
}

std::unique_ptr<AbstractCreature> Room::creature() {
    return std::move(_creature);
}

void Room::setCreature(std::unique_ptr<AbstractCreature> newCreature) {
    _creature = std::move(newCreature);
}

void Room::setEdge(const std::shared_ptr<RoomEdge> edge, const Direction &direction) {
    // return the edge at the given direction enum value (North = 0, South = 1, East = 2, West = 3)
    _edges[static_cast<std::underlying_type<Direction>::type>(direction)] = edge;
}

std::shared_ptr<RoomEdge> Room::edgeAt(const Direction &direction) const {
    // return the edge at the given direction enum value (North = 0, South = 1, East = 2, West = 3)
    return _edges[static_cast<std::underlying_type<Direction>::type>(direction)];
}

} // namespace core::dungeon
