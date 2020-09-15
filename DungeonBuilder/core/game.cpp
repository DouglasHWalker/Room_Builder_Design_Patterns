#include <random>
#include <ctime>
#include "game.h"
Game* Game::theInstance = nullptr;
void Game::setDungeonType(std::shared_ptr<DungeonLevelBuilder> dungeonLevelBuilder){
    _dungeonBuilder = dungeonLevelBuilder;
}
void Game::createExampleLevel(){
    std::string title = "Example Dungeon Level";
    int width = 3;
    int height = 3;

    _dungeonBuilder->buildDungeonLevel(title, width, height);
    // build all the dungeon rooms
    std::shared_ptr<Room> room1 = _dungeonBuilder->buildRoom(1);
    std::shared_ptr<Room> room2 = _dungeonBuilder->buildRoom(2);
    std::shared_ptr<Room> room3 = _dungeonBuilder->buildRoom(3);
    std::shared_ptr<Room> room4 = _dungeonBuilder->buildRoom(4);
    std::shared_ptr<Room> room5 = _dungeonBuilder->buildRoom(5);
    std::shared_ptr<Room> room6 = _dungeonBuilder->buildRoom(6);
    std::shared_ptr<Room> room7 = _dungeonBuilder->buildRoom(7);
    std::shared_ptr<Room> room8 = _dungeonBuilder->buildRoom(8);
    std::shared_ptr<Room> room9 = _dungeonBuilder->buildRoom(9);

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

    // build items
    _dungeonBuilder->buildItem(room3);
    _dungeonBuilder->buildItem(room5);
    _dungeonBuilder->buildItem(room7);

    // build creatures
    _dungeonBuilder->buildCreature(room3);
    _dungeonBuilder->buildCreature(room5);
    _dungeonBuilder->buildCreature(room9);

    // build entrance
    _dungeonBuilder->buildEntrance(room1, Room::Direction::North);

    // build exit
    _dungeonBuilder->buildExit(room9, Room::Direction::East);



    // get dungeon level, return to display
    _dungeonLevel = _dungeonBuilder->getDungeonLevel(); // FIXME: bare pointer requires .get() this may be very wrong

}
void Game::createRandomLevel(std::string name, int width, int height){}

std::vector<std::string> Game::displayLevel(){
    return _dungeonLevel->display();
}

std::string Game::describeLevel(){
    return _dungeonLevel->description();
}

int Game::getNumberOfRooms(){
    return _dungeonLevel->width() * _dungeonLevel->height();
}

std::string Game::describeRoom(int roomNumber){
    return _dungeonLevel->retrieveRoom(roomNumber)->description();
}

double Game::randomDouble(){
    return _realDistribution(_randomGenerator);
}
