#include "basicdungeonlevelbuilder.h"
#include "core/dungeon/doorway.h"

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){
    _dungeonLevel = new DungeonLevel(name, width, height);
}
void BasicDungeonLevelBuilder::buildRoom(int id){
    Room *room = new Room(id);
    _dungeonLevel->addRoom(room);
}
void BasicDungeonLevelBuilder::buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints){
    // TODO: connect the doors to the rooms
}
void BasicDungeonLevelBuilder::buildEntrance(Room room, Room::Direction direction){
    // TODO: connect the doors to the rooms
}
void BasicDungeonLevelBuilder::buildExit(Room room, Room::Direction direction){
    // TODO: connect the doors to the rooms
}
void BasicDungeonLevelBuilder::buildItem(Room room){
    // TODO: prototype model Items
}
void BasicDungeonLevelBuilder::buildCreature(Room room){
    // TODO: prototype model Creatures
}
