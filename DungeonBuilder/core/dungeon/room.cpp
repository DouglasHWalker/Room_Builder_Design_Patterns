#include "room.h"

Room::Room(int id) : _id{id} {
    _edges = std::array<std::shared_ptr<RoomEdge>, 4>(); // TODO: make the edges and edge array smart pointers?
}

std::vector<std::string> Room::display(){
     std::vector<std::string> output = std::vector<std::string>();
     // Create North Row string
     std::string northRow{"+----"};
     northRow += edgeAt(Room::Direction::North)->displayCharacter();
     northRow += "----+";
     // Create Blank Row
     std::string blankRow = "|         |";
     // Create Middle Row
     std::string middleRow{};
     middleRow += edgeAt(Room::Direction::West)->displayCharacter();
     middleRow += "   ";
     middleRow += _creature->displayCharacter();
     middleRow += _item->displayCharacter();
     middleRow +=  "   ";
     middleRow += edgeAt(Room::Direction::East)->displayCharacter();
     // Create South Row
     std::string southRow{"+----"};
     southRow += edgeAt(Room::Direction::South)->displayCharacter();
     southRow += "----+";

     // Add strings to output
     output.push_back(northRow);
     output.push_back(blankRow);
     output.push_back(middleRow);
     output.push_back(blankRow);
     output.push_back(southRow);

     return output;
}

int Room::id(){
    return _id;
}

std::unique_ptr<Item> Room::item(){
    return std::move(_item);
}

void Room::setItem(std::unique_ptr<Item>& newItem){
    _item = std::move(newItem);
}

std::unique_ptr<AbstractCreature> Room::creature(){
    return std::move(_creature);
}

void Room::setCreature(std::unique_ptr<AbstractCreature> newCreature){
    _creature = std::move(newCreature);
}

void Room::setEdge(std::shared_ptr<RoomEdge> edge, Room::Direction direction){
    // return the edge at the given direction enum value (North = 1, South = 2, East = 3, West = 4)
    _edges[static_cast<std::underlying_type<Room::Direction>::type>(direction)] = edge;
}

std::shared_ptr<RoomEdge> Room::edgeAt(Room::Direction direction){
    // return the edge at the given direction enum value (North = 1, South = 2, East = 3, West = 4)
    return _edges[static_cast<std::underlying_type<Room::Direction>::type>(direction)];
}
