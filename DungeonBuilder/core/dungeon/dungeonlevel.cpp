#include <iostream>
#include "dungeonlevel.h"

void DungeonLevel::addRoom(std::shared_ptr<Room> room){
    _rooms.push_back(room);
}
std::shared_ptr<Room> DungeonLevel::retrieveRoom(int id){
    return _rooms[id - 1];
}
int DungeonLevel::width(){
    return _width;
}
int DungeonLevel::height(){
    return _height;
}
std::string DungeonLevel::name(){
    return _name;
}
std::vector<std::string> DungeonLevel::display(){
    // initialise a vector based on height of dungeon level
    std::vector<std::string> dungeonLevelString = std::vector<std::string>();
    int numberOfRowsInRoom = 6; // including space below
    int numRowsInOutputString = (height() * numberOfRowsInRoom) - 1;
    for(int i{0}; i < numRowsInOutputString; i++){
        dungeonLevelString.push_back("");
    }
    // for each row of rooms (height)
    for (int r{0}; r < _height; r++){
        // for each column of rooms (width)
        for (int c{0}; c < _width; c++) {
            // retrieve the next room, add display to output
            // for every row of chars in the room
            for(int roomCol{0}; roomCol < 5; roomCol++){ // 4 = room height -1
                // add the row of chars to the appropriate row in output string
                dungeonLevelString.at(roomCol + (r * numberOfRowsInRoom)) += _rooms[c + (r * _width)]->display()[roomCol];
                // if we are at the middle row, add a dashed line bewteen the rooms, otherwise add space
                if(c != _width -1){
                    dungeonLevelString.at(roomCol + (r * numberOfRowsInRoom)) += roomCol == 2 ? "--" : "  ";
                }
            }
        }
        // add the seperator row between rows of rooms, unless we just printed the last row
        if(r != _height -1){
            for(int i{0}; i < _width; i++){
                dungeonLevelString.at((r + 1)* (numberOfRowsInRoom) - 1) += "     |       "; // FIXME: adding the spaces bewteen the rooms
            }

        }
    }
    // add dungeon name to output
    dungeonLevelString.insert(dungeonLevelString.begin(), name());
    return dungeonLevelString;
}

