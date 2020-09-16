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
    _dungeonBuilder->buildDoorway(room1, room4, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    // room2
    //    _dungeonBuilder->buildDoorway(room2, room1, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room2, room3, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::OriginImpassable | DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    _dungeonBuilder->buildDoorway(room2, room5, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::None);
    // room 3
    //    _dungeonBuilder->buildDoorway(room3, room2, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::OriginImpassable);
    _dungeonBuilder->buildDoorway(room3, room6, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::DestinationLocked);
    // room 4
    // did not include door going from 4 to 1 (its one way)
    _dungeonBuilder->buildDoorway(room4, room5, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    _dungeonBuilder->buildDoorway(room4, room7, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::OriginImpassable | DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    // room 5
    // did not include door from 5 to 4 (its one way)
    //    _dungeonBuilder->buildDoorway(room5, room2, Room::Direction::North, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room5, room6, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room5, room8, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::None);
    // room 6
    //    _dungeonBuilder->buildDoorway(room6, room3, Room::Direction::North, DungeonLevelBuilder::MoveConstraints::OriginLocked);
    //    _dungeonBuilder->buildDoorway(room6, room5, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::None);
    // room 7
    //    _dungeonBuilder->buildDoorway(room7, room4, Room::Direction::North, DungeonLevelBuilder::MoveConstraints::OriginImpassable);
    _dungeonBuilder->buildDoorway(room7, room8, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::OriginLocked | DungeonLevelBuilder::MoveConstraints::DestinationLocked);
    // room 8
    //    _dungeonBuilder->buildDoorway(room8, room5, Room::Direction::North, DungeonLevelBuilder::MoveConstraints::None);
    //    _dungeonBuilder->buildDoorway(room8, room7, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::OriginLocked);
    _dungeonBuilder->buildDoorway(room8, room9, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None);
    // room 9
    //    _dungeonBuilder->buildDoorway(room9, room8, Room::Direction::West, DungeonLevelBuilder::MoveConstraints::None);
    // WARNING: clean up commentted out doorways

    // build items
    _dungeonBuilder->buildItem(room3);
    _dungeonBuilder->buildItem(room5);
    _dungeonBuilder->buildItem(room7);

    // build creatures
    _dungeonBuilder->buildCreature(room3);
    _dungeonBuilder->buildCreature(room5);
    _dungeonBuilder->buildCreature(room9);

    // build entrance and exit
    _dungeonBuilder->buildEntrance(room1, Room::Direction::North);
    _dungeonBuilder->buildExit(room9, Room::Direction::East);

    // set dungeon level to newly created level
    _dungeonLevel = _dungeonBuilder->getDungeonLevel(); // FIXME: bare pointer requires .get() this may be very wrong

}
void Game::createRandomLevel(std::string name, int width, int height){

    _dungeonBuilder->buildDungeonLevel(name, width, height);
    // random between 1-11 modulus width
    int entranceRoom = (rand() % width + 1); // a room somewhere in the first row
    int exitRoom = ((height - 1) * width) + (rand() % width + 1);// a room somewhere in the last row


    // ROOMS
    // build the dungeon rooms
    std::vector<std::shared_ptr<Room>> rooms = std::vector<std::shared_ptr<Room>>();
    for(int i{0}; i <= width * height; i++) {
        rooms[i] = _dungeonBuilder->buildRoom(i + 1);
    }

    // add components
    for(int row{1}; row <= height; row++) {
        for(int col{1}; col <= width; col++) {

            int roomId = (row - 1 * width) + col;
            double random = randomDouble();
            std::shared_ptr<Room> room = _dungeonBuilder->getDungeonLevel()->retrieveRoom(roomId);
            addRandomDoorways(row, col, room);








            // CREATURES
            double creature_roll = randomDouble();
            if(creature_roll <= CREATURE_CHANCE and roomId != entranceRoom){

            }
            // if exit room, add creature
            if(roomId == exitRoom){

            }

            // ITEMS
            double item_roll = randomDouble();
            double weapon_roll = randomDouble();
            if(item_roll <= ITEM_CHANCE and roomId != entranceRoom){
                // if weapon
                if(weapon_roll <= WEAPON_CHANCE){

                }
            }
            // if exit room,
            if(item_roll <= ITEM_CHANCE and roomId == exitRoom){
                // if weapon
                if(weapon_roll <= WEAPON_CHANCE){

                }
            }
            int oneOrTwo = rand() % 2 + 1;


            // ENTRY & EXIT
            oneOrTwo = rand() % 2 + 1;
            // if 1x1
            if(width * height == 1){
                // get two different random directions
                int entryRandEdge = rand() % 4 + 1;
                int exitRandEdge = rand() % 4 + 1;
                while(exitRandEdge == entryRandEdge){
                    exitRandEdge = rand() % 4 + 1;
                }
                // build entry
                buildRandomEntry(static_cast<Room::Direction>(entryRandEdge));
                // build exit
                buildRandomExit(static_cast<Room::Direction>(exitRandEdge));
            } else if(entranceRoom == exitRoom and roomId == entranceRoom){ // if entry in same room and we are building that room
                // if in a corner
                if(roomId == 1){ // top left corner
                    // North or West
                    buildRandomEntry(oneOrTwo == 1 ? Room::Direction::North : Room::Direction::West);
                    buildRandomExit(oneOrTwo == 0 ? Room::Direction::North : Room::Direction::West);
                } else if(roomId == width){ // top right corner
                    // North or East
                    buildRandomEntry(oneOrTwo == 1 ? Room::Direction::North : Room::Direction::East);
                    buildRandomExit(oneOrTwo == 0 ? Room::Direction::North : Room::Direction::East);
                } else if(roomId == height){ // bottom left corner
                    // South or West
                    buildRandomEntry(oneOrTwo == 1 ? Room::Direction::South : Room::Direction::West);
                    buildRandomExit(oneOrTwo == 0 ? Room::Direction::South : Room::Direction::West);
                } else if(roomId == width * height){ // bottom right corner
                    // South or East
                    buildRandomEntry(oneOrTwo == 1 ? Room::Direction::South : Room::Direction::East);
                    buildRandomExit(oneOrTwo == 0 ? Room::Direction::South : Room::Direction::East);
                } else { // Not in corner room, must have at least two doorways
                    for(int i{0}; i < oneOrTwo; i++){
                        // build entry
                        buildRandomEntry(Room::Direction::North);
                        // build exit
                        buildRandomExit(Room::Direction::South);
                    }
                }
            } else { // not in same room
                // if on entrance room
                if(roomId == entranceRoom) {
                    // if in a corner
                    if(roomId == 1) { // top left corner
                        // North or West
                        buildRandomEntry(oneOrTwo == 1 ? Room::Direction::North : Room::Direction::West);
                    } else if(roomId == width){ // top right corner
                        // North or East
                        buildRandomEntry(oneOrTwo == 1 ? Room::Direction::North : Room::Direction::East);
                    } else { // not in a corner
                        // North Wall
                        buildRandomEntry(Room::Direction::North);
                    }
                }
                // if on exit room, build exit
                if(roomId == exitRoom) {
                    // if in a corner
                    if(roomId == height) { // bottom left corner
                        // South or West
                        buildRandomEntry(oneOrTwo == 1 ? Room::Direction::North : Room::Direction::West);
                    } else if(roomId == width * height){ // bottom right corner
                        // South or East
                        buildRandomEntry(oneOrTwo == 1 ? Room::Direction::North : Room::Direction::West);
                    } else { // not in a corner
                        // South Wall
                        buildRandomEntry(Room::Direction::South);
                    }
                }
            }
        }
    }
    // set dungeon level to newly created level
    _dungeonLevel = _dungeonBuilder->getDungeonLevel();
}

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

// Helper methods
void Game::addRandomDoorways(int row, int col, std::shared_ptr<Room> room){
    int roomId = room->id();
    int oneOrTwo = rand() % 2 + 1;
    int randDir = rand() % 3 + 1;
    double random = randomDouble();
    int width = _dungeonLevel->width();
    int height = _dungeonLevel->width();
    // NOTE: could do this with a switch using a int[] like a truth table
    // if in a corner room, must have at least one doorway
    if(roomId == 1){ // top left corner
        // South or East
        buildRandomDoorway(random, oneOrTwo == 1 ? Room::Direction::South : Room::Direction::East);
    } else if(roomId == width){ // top right corner
        // South or West
        buildRandomDoorway(random, oneOrTwo == 1 ? Room::Direction::South : Room::Direction::West);
    } else if(roomId == height){ // bottom left corner
        // North or East
        buildRandomDoorway(random, oneOrTwo == 1 ? Room::Direction::North : Room::Direction::East);
    } else if(roomId == width * height){ // bottom right corner
        // North or West
        buildRandomDoorway(random, oneOrTwo == 1 ? Room::Direction::North : Room::Direction::West);
    } else { // Not is corner room, must have at least two doorways

        for(int i{0}; i < oneOrTwo; i++){
            if(row == 1){ // if on top row
                // east, south, west
                switch(randDir){
                case 1:
                    buildRandomDoorway(random, Room::Direction::East);
                    break;
                case 2:
                    buildRandomDoorway(random, Room::Direction::South);
                    break;
                case 3:
                    buildRandomDoorway(random, Room::Direction::West);
                    break;
                }
            } else if (row == height){ // if on bottom row
                // north, east, west
                switch(randDir){
                case 1:
                    buildRandomDoorway(random, Room::Direction::East);
                    break;
                case 2:
                    buildRandomDoorway(random, Room::Direction::North);
                    break;
                case 3:
                    buildRandomDoorway(random, Room::Direction::West);
                    break;
                }
            } else if (col == 1){ // if on left most column
                // north, east, south
                switch(randDir){
                case 1:
                    buildRandomDoorway(random, Room::Direction::East);
                    break;
                case 2:
                    buildRandomDoorway(random, Room::Direction::North);
                    break;
                case 3:
                    buildRandomDoorway(random, Room::Direction::South);
                    break;
                }
            } else if (col == width){ // if on right most column
                // north, south, west
                switch(randDir){
                case 1:
                    buildRandomDoorway(random, Room::Direction::West);
                    break;
                case 2:
                    buildRandomDoorway(random, Room::Direction::North);
                    break;
                case 3:
                    buildRandomDoorway(random, Room::Direction::South);
                    break;
                }
            } else { // not on top or bottom row, not on left or right column
                // north, east, south, west
                randDir = rand() % 4 + 1;
                buildRandomDoorway(random, static_cast<Room::Direction>(randDir));
            }
        }
    }
}

void Game::buildRandomDoorway(double random, Room::Direction direction){

}

void Game::buildRandomEntry(Room::Direction direction){

}

void Game::buildRandomExit(Room::Direction direction){

}
