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
std::vector<std::string> DungeonLevel::display() const{
    std::vector<std::string> dungeonLevelMap = std::vector<std::string>();
    int numberOfRowsInRoom = 6; // 5 rows in room + 1 for the space below the room
    int numRowsInOutputString = (height() * numberOfRowsInRoom);
    // initialise dungeon level vector with blank values
    for(int i{0}; i < numRowsInOutputString; ++i) {
        dungeonLevelMap.push_back("");
    }
    // for each row of rooms (height)
    for (int row{0}; row < _height; ++row) {
        // for each column of rooms (width)
        for (int col{0}; col < _width; ++col) {
            // retrieve the string display for room, at [row, column]
            std::array<std::string, 6> roomDisplay = _rooms.at(col + (row * _width) + 1)->display();
            // for every row of strings in the room
            for(int roomRow{0}; roomRow < numberOfRowsInRoom; ++roomRow) {
                // add the row of chars to the appropriate row in output string
                dungeonLevelMap.at(roomRow + (row * numberOfRowsInRoom)) += roomDisplay[roomRow];
            }
        }
    }
    // add dungeon name to output
    dungeonLevelMap.insert(dungeonLevelMap.begin(), name());
    return dungeonLevelMap;
}

} // namespace core::dungeon
