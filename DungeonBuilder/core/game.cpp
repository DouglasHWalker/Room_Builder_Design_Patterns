#include <random>
#include <ctime>
#include "game.h"

Game::Game(){}

 Game& Game::instance(){
    return theInstance;
}

void setDungeonType(DungeonLevelBuilder dungeonLevelBuilder){}
void Game::createExampleLevel(){
    std::string title = "Example Dungeon Level";
    int width = 3;
    int height = 3;

    _dungeonBuilder->buildDungeonLevel(title, width, height);
    // build all the dungeon rooms
    Room *room1 = _dungeonBuilder->buildRoom(1);
    Room *room2 = _dungeonBuilder->buildRoom(2);
    Room *room3 = _dungeonBuilder->buildRoom(3);
    Room *room4 = _dungeonBuilder->buildRoom(4);
    Room *room5 = _dungeonBuilder->buildRoom(5);
    Room *room6 = _dungeonBuilder->buildRoom(6);
    Room *room7 = _dungeonBuilder->buildRoom(7);
    Room *room8 = _dungeonBuilder->buildRoom(8);
    Room *room9 = _dungeonBuilder->buildRoom(9);

    // add the apropriate doorways to the rooms
    // room1
    _dungeonBuilder->buildDoorway(room1, room2, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None); // TODO: change move contraints to use bitwise notation
    _dungeonBuilder->buildDoorway(room1, room4, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::None);
    // room2
    _dungeonBuilder->buildDoorway(room2, room1, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room2, room3, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::OriginImpassable);
    _dungeonBuilder->buildDoorway(room2, room5, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::None);
    // room 3
    _dungeonBuilder->buildDoorway(room3, room2, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::OriginImpassable);
    _dungeonBuilder->buildDoorway(room3, room6, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::DestinationLocked);
    // room 4
    // did not include door going from 4 to 1 (its one way)
    _dungeonBuilder->buildDoorway(room4, room5, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room4, room7, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::OriginImpassable);
    // room 5
    // did not include door from 5 to 4 (its one way)
    _dungeonBuilder->buildDoorway(room5, room2, Room::Direction::North, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room5, room6, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room5, room8, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::None);
    // room 6
    _dungeonBuilder->buildDoorway(room6, room3, Room::Direction::North, DungeonLevelBuilder::MoveConstraints::OriginLocked);
    _dungeonBuilder->buildDoorway(room6, room5, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::None);
    // room 7
    _dungeonBuilder->buildDoorway(room7, room4, Room::Direction::North, DungeonLevelBuilder::MoveConstraints::OriginImpassable);
    _dungeonBuilder->buildDoorway(room7, room8, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::OriginLocked);
    // room 8
    _dungeonBuilder->buildDoorway(room8, room5, Room::Direction::North, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room8, room7, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::OriginLocked);
    _dungeonBuilder->buildDoorway(room8, room9, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None);
    // room 9
    _dungeonBuilder->buildDoorway(room9, room8, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::None);

    // build entrance
    _dungeonBuilder->buildEntrance(room1, Room::Direction::North);

    // build exit
    _dungeonBuilder->buildExit(room9, Room::Direction::East);

    // build items
    _dungeonBuilder->buildItem(room3);
    _dungeonBuilder->buildItem(room5);
    _dungeonBuilder->buildItem(room7);

    // build creatures
    _dungeonBuilder->buildCreature(room3);
    _dungeonBuilder->buildCreature(room5);
    _dungeonBuilder->buildCreature(room9);

    // get dungeon level, return to display
    _dungeonLevel = _dungeonBuilder->getDungeonLevel();

}
void Game::createRandomLevel(std::string name, int width, int height){}
std::vector<std::string> Game::displayLevel(){
    // turn the level into the strings for the map

}
double Game::randomDouble(){
    return _realDistribution(_randomGenerator);
}
