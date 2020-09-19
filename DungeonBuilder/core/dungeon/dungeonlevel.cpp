#include "dungeonlevel.h"
namespace core::dungeon {

void DungeonLevel::addRoom(const std::shared_ptr<Room> room) {
    _rooms.insert(std::make_pair(room->id(), room));
}
std::shared_ptr<Room> DungeonLevel::retrieveRoom(const int id) const{
    return _rooms.at(id);
}
int DungeonLevel::width() const{
    return _width;
}
int DungeonLevel::height() const{
    return _height;
}
std::string DungeonLevel::name() const{
    return _name;
}
std::vector<std::string> DungeonLevel::display() const{ // TODO: use output operators, make a little more consise and practical
    std::vector<std::string> dungeonLevelMap = std::vector<std::string>();
    int numberOfRowsInRoom = 6; // 5 rows in room + 1 for the space below the room
    int numRowsInOutputString = (height() * numberOfRowsInRoom) - 1;
    std::shared_ptr<Room> currentRoom;
    // initialise dungeon level vector with blank values
    for(int i{0}; i < numRowsInOutputString; ++i) {
        dungeonLevelMap.push_back("");
    }
    // for each row of rooms (height)
    for (int row{0}; row < _height; ++row) {
        // for each column of rooms (width)
        for (int col{0}; col < _width; ++col) {
            // retrieve the room, at [row, column]
            currentRoom =_rooms.at(col + (row * _width) + 1);
            // for every row of strings in the room
            for(int roomCol{0}; roomCol < 5; ++roomCol) { // 5 = num rows in room (excluding bottom space)
                // add the row of chars to the appropriate row in output string
                dungeonLevelMap.at(roomCol + (row * numberOfRowsInRoom)) += currentRoom->display()[roomCol];
            }
            // if we are not at the last row of rooms
            if(row != _height - 1) {
                int lastDungeonRowStringIndex = (row + 1) * (numberOfRowsInRoom) - 1;
                // add the seperator row between rows of rooms for the current room, add passage if necessary
                dungeonLevelMap.at(lastDungeonRowStringIndex) +=
                    currentRoom->edgeAt(Room::Direction::South)->isPassage() ? "     |       " : "             ";
            }
        }
    }
    // add dungeon name to output
    dungeonLevelMap.insert(dungeonLevelMap.begin(), name());
    return dungeonLevelMap;
}

} // namespace core::dungeon
