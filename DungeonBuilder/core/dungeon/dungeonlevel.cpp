#include <iostream>
#include "dungeonlevel.h"


DungeonLevel::DungeonLevel(std::string name, int width, int height) : _name{name}, _width{width}, _height{height} {}

void DungeonLevel::addRoom(Room *room){
    // rooms.add(room);...
}
Room DungeonLevel::retrieveRoom(int){}
int DungeonLevel::width(){}
int DungeonLevel::height(){}
std::string DungeonLevel::name(){}
std::vector<std::string> DungeonLevel::display(){ // TODO: should I be using vector here

}

