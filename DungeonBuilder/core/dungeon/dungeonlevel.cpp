#include <iostream>
#include "dungeonlevel.h"

void DungeonLevel::addRoom(std::shared_ptr<Room> room){
    _rooms.push_back(room);
}
std::shared_ptr<Room> DungeonLevel::retrieveRoom(int id){
    return _rooms[id];
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
    std::vector<std::string> vect = std::vector<std::string>();
    vect.push_back("TO BE IMPLEMENTED, dungeonLevel.display()");
    return vect;
}

