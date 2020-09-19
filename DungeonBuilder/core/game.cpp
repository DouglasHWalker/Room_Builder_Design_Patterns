#include "game.h"
namespace core {

using core::dungeon::DungeonLevel;
using core::dungeon::DungeonLevelBuilder;
using core::dungeon::Room;

Game* Game::theInstance = nullptr;

void Game::setDungeonType(DungeonLevelBuilder* dungeonLevelBuilder) {
    _dungeonBuilder = dungeonLevelBuilder;
}

void Game::createExampleLevel() {
    _dungeonBuilder->buildDungeonLevel(_EXAMPLE_TITLE, _EXAMPLE_WIDTH, _EXAMPLE_HEIGHT);
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

    // add doorways to the rooms
    // room1
    _dungeonBuilder->buildDoorway(room1, room2, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None); // TODO: change move contraints to use bitwise notation
    _dungeonBuilder->buildDoorway(room1, room4, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    // room2
    _dungeonBuilder->buildDoorway(room2, room3, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::OriginImpassable | DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    _dungeonBuilder->buildDoorway(room2, room5, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::None);
    // room 3
    _dungeonBuilder->buildDoorway(room3, room6, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::DestinationLocked);
    // room 4
    _dungeonBuilder->buildDoorway(room4, room5, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    _dungeonBuilder->buildDoorway(room4, room7, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::OriginImpassable | DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    // room 5
    _dungeonBuilder->buildDoorway(room5, room6, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None);
    _dungeonBuilder->buildDoorway(room5, room8, Room::Direction::South, DungeonLevelBuilder::MoveConstraints::None);
    // room 7
    _dungeonBuilder->buildDoorway(room7, room8, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::OriginLocked | DungeonLevelBuilder::MoveConstraints::DestinationLocked);
    // room 8
    _dungeonBuilder->buildDoorway(room8, room9, Room::Direction::East, DungeonLevelBuilder::MoveConstraints::None);

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
    _dungeonLevel = _dungeonBuilder->getDungeonLevel();
}

void Game::createRandomLevel(const std::string &name, const int width, const int height) {

    _dungeonBuilder->buildDungeonLevel(name, width, height);
    int entranceRoom = (rand() % width + 1); // a room somewhere in the first row
    int exitRoom = ((height - 1) * width) + (rand() % width + 1);// a room somewhere in the last row

    // ROOMS
    // build the dungeon rooms
    std::map<int, std::shared_ptr<Room>> builtRooms;
    int numRooms = width * height;
    // for every room
    for(int i{1}; i <= numRooms; ++i) {
        // retrieve room
        std::shared_ptr<Room> room;
        // if room has not yet been built, build it
        if(builtRooms.find(i) == builtRooms.end()) {
            room = _dungeonBuilder->buildRoom(i);
            builtRooms.insert(std::make_pair(i, room));
        } else { // otherwise get the existing room
            room = builtRooms.at(i);
        }
        // if room has neighbours, i.e. level dimensions != 1x1
        if(numRooms != 1) {
            // build valid neighbours of current room
            std::map<int, std::shared_ptr<Room>> & builtRoomsRef = builtRooms;
            std::vector<std::tuple<std::shared_ptr<Room>, Room::Direction>> neighbours = buildNeighbours(i, width, height, builtRoomsRef);
            // build doorways randomly to the rooms neighbours
            buildRandomNeighbouringDoorways(room, width, height, neighbours);
        }
    }
    // fill rooms with consumables and creatures
    for(int id{1}; id <= numRooms; ++id) {
        std::shared_ptr<Room> room = builtRooms.at(id);
        // CREATURES
        if(randomDouble() <= _CREATURE_CHANCE and id != entranceRoom) {
            _dungeonBuilder->buildCreature(room);
        }
        // if exit room, add creature
        if(id == exitRoom) {
            _dungeonBuilder->buildCreature(room);
        }
        // ITEMS
        if(randomDouble() <= _ITEM_CHANCE and id != entranceRoom) {
            _dungeonBuilder->buildItem(room);
        }
        // if exit room,
        if(id == exitRoom) {
            _dungeonBuilder->buildItem(room);
        }

        // ENTRY
        Room::Direction entryDirection;
        Room::Direction exitDirection;
        if(id == entranceRoom) {
            int randDir = rand() % 2;
            if(entranceRoom == 1) { // North, West corner
                entryDirection = randDir == 0 ? Room::Direction::North : Room::Direction::West;
            } else if(entranceRoom == width) { // North, East corner
                entryDirection = randDir == 0 ? Room::Direction::North : Room::Direction::East;
            } else { // Top row, not corners
                entryDirection = Room::Direction::North;
            }
            _dungeonBuilder->buildEntrance(room, entryDirection);
        }
        // EXIT
        if(id == exitRoom) {
            // determine all valid directions
            std::set<Room::Direction> validDirections;
            if(exitRoom == 1) { // South, West corner
                validDirections.insert(Room::Direction::South);
                validDirections.insert(Room::Direction::West);
            } else if(exitRoom == width) { // South, East corner
                validDirections.insert(Room::Direction::South);
                validDirections.insert(Room::Direction::East);
            } else { // Top row, not corners
                validDirections.insert(Room::Direction::South);
            }
            // if in entrance room, remove entrance direction from avalible options
            if(id == entranceRoom) { validDirections.erase(entryDirection); }
            // random direction
            int randDir = rand() % validDirections.size();
            auto it = validDirections.begin();
            for (int i{0}; i < randDir; ++i) {++it;}
            exitDirection = *it;
            // build exit
            _dungeonBuilder->buildExit(room, exitDirection);
        }
    }
    // set dungeon level to newly created level
    _dungeonLevel = _dungeonBuilder->getDungeonLevel();
}

std::vector<std::string> Game::displayLevel() const{
    return _dungeonLevel->display();
}

std::string Game::getDungeonLevelDescription() const{
    return _dungeonLevel->description();
}

int Game::getNumberOfRooms() const{
    return _dungeonLevel->width() * _dungeonLevel->height();
}

std::string Game::getRoomDescription(int roomNumber) const{
    return _dungeonLevel->retrieveRoom(roomNumber)->description();
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

// Helper methods
namespace  {


}
std::vector<std::tuple<std::shared_ptr<Room>, Room::Direction>> Game::buildNeighbours(const int roomId, int width, int height, std::map<int, std::shared_ptr<Room>> &builtRooms) const{
    std::vector<std::tuple<int, Room::Direction>> validNeighbours;
    std::vector<std::tuple<std::shared_ptr<Room>, Room::Direction>> neighbours;
    int numRooms = width * height;
    // determine which neighbours are valid
    if(width != 1) {  // if not in a single column map, add horizontal neighbour
        switch (roomId % width) {
        case 0: // right column
            validNeighbours.push_back(std::make_pair(roomId - 1, Room::Direction::West)); // West neighbor
            break;
        case 1: // left column
            validNeighbours.push_back(std::make_pair(roomId + 1, Room::Direction::East)); // East neighbor
            break;
        default: // middle-column
            validNeighbours.push_back(std::make_pair(roomId - 1, Room::Direction::West)); // West neighbor
            validNeighbours.push_back(std::make_pair(roomId + 1, Room::Direction::East)); // East neighbor
            break;
        }
    }
    // room row
    if(height != 1) {  // if not single row map, add vertical neighbour
        if(roomId >= 1 and roomId <= width) { // first row,
            validNeighbours.push_back(std::make_pair(roomId + width, Room::Direction::South)); // South neighbor
        } else if(roomId >= numRooms - width and roomId <= numRooms) {  // last row
            validNeighbours.push_back(std::make_pair(roomId - width, Room::Direction::North)); // North neighbor
        } else { // middle-row
            validNeighbours.push_back(std::make_pair(roomId + width, Room::Direction::South)); // South neighbor
            validNeighbours.push_back(std::make_pair(roomId - width, Room::Direction::North)); // North neighbor
        }
    }
    // build neighbours
    std::shared_ptr<Room> neighbour;
    for(int j{0}; j < static_cast<int>(validNeighbours.size()); ++j) {
        // if neighbour has not been built yet, build neighbour
        int id = std::get<0>(validNeighbours[j]);
        if(builtRooms.find(id) == builtRooms.end()) {
            neighbour = _dungeonBuilder->buildRoom(id);
            builtRooms.insert(std::make_pair(id, neighbour));
        } else { // otherwise get the existing neighbour
            neighbour = builtRooms.at(id);
        }
        // add neighbour to list of rooms neighbours
        neighbours.push_back(std::make_pair(neighbour, std::get<1>(validNeighbours[j])));
    }
    return neighbours;
}

DungeonLevelBuilder::MoveConstraints Game::getRandomMovementConstraints() {
    int constraints = 0;
    // generate origin constraints
    double random = randomDouble();
    if(random <= _IMPASSABLE_CHANCE) { constraints += 1; } // origin impassable
    else if (random <= _LOCKED_CHANCE + _IMPASSABLE_CHANCE) { constraints += 2; } // origin locked
    //  generate destination constraints
    random = randomDouble();
    if(random <= _IMPASSABLE_CHANCE) { constraints += 4; } // destination impassable
    else if (random <= _LOCKED_CHANCE + _IMPASSABLE_CHANCE) { constraints += 8; } // destination locked

    switch (constraints) {
    case 0: // both traversable
        return DungeonLevelBuilder::MoveConstraints::None;
    case 1: // origin impassable, dest traversable
        return DungeonLevelBuilder::MoveConstraints::OriginImpassable;
    case 2: // origin locked, dest traversable
        return DungeonLevelBuilder::MoveConstraints::OriginLocked;
    case 4: // origin traversable, destination impassable
        return DungeonLevelBuilder::MoveConstraints::DestinationImpassable;
    case 5: // both impassable
        return DungeonLevelBuilder::MoveConstraints::OriginImpassable | DungeonLevelBuilder::MoveConstraints::DestinationImpassable;
    case 6: // origin locked, dest impassable
        return DungeonLevelBuilder::MoveConstraints::OriginLocked | DungeonLevelBuilder::MoveConstraints::DestinationImpassable;
    case 8: // origin passable, dest locked
        return DungeonLevelBuilder::MoveConstraints::DestinationLocked;
    case 9: // origin impassable, dest locked
        return DungeonLevelBuilder::MoveConstraints::OriginImpassable | DungeonLevelBuilder::MoveConstraints::DestinationLocked;
    case 10: // both locked
        return DungeonLevelBuilder::MoveConstraints::OriginLocked | DungeonLevelBuilder::MoveConstraints::DestinationLocked;
    default:
        return DungeonLevelBuilder::MoveConstraints::None;
    }
}

void Game::buildRandomNeighbouringDoorways(std::shared_ptr<Room> room, int width, int height, std::vector<std::tuple<std::shared_ptr<Room>, Room::Direction>> &neighbours) {
    int randDir = 0;
    // depending on the number of neighbours
    switch (neighbours.size()) {
    case 1: // if only 1 neighbour, we are in a corner of a single row or column map
        _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[0]), std::get<1>(neighbours[0]), getRandomMovementConstraints());
        break;
    case 2: // if only 2 neighbours, we are in a corner, or a middle room for a single row or columnn map
        if(width == 1 || height == 1) { // single row or column map, build both neighbours
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[0]), std::get<1>(neighbours[0]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[1]), std::get<1>(neighbours[1]), getRandomMovementConstraints());
        } else { // normal map
            // randomly build doors to 1 neighbour
            randDir = rand() % 2 + 1; // 2 different possibilities
            switch (randDir) {
            case 1: // build doorway to first neighbour
                _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[0]), std::get<1>(neighbours[0]), getRandomMovementConstraints());
                break;
            case 2: // build doorway to second neighbour
                _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[1]), std::get<1>(neighbours[1]), getRandomMovementConstraints());
                break;
            default:
                break;
            }
        }
        break;
    case 3: // if 3 neighbours, we are in an outside row or column
        randDir = rand() % 3 + 1; // 3 different possibilities
        switch (randDir) {
        case 1: // build doorways to first and second neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[0]), std::get<1>(neighbours[0]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[1]), std::get<1>(neighbours[1]), getRandomMovementConstraints());
            break;
        case 2: // build doorway to first and third neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[0]), std::get<1>(neighbours[0]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[2]), std::get<1>(neighbours[2]), getRandomMovementConstraints());
            break;
        case 3: // build doorway to second and third neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[1]), std::get<1>(neighbours[1]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[2]), std::get<1>(neighbours[2]), getRandomMovementConstraints());
            break;
        }
        break;
    case 4: // 4, a central room
        randDir = rand() % 6 + 1; // 6 different possibilities
        switch (randDir) {
        case 1: // build doorways to first and second neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[0]), std::get<1>(neighbours[0]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[1]), std::get<1>(neighbours[1]), getRandomMovementConstraints());
            break;
        case 2: // build doorway to first and third neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[0]), std::get<1>(neighbours[0]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[2]), std::get<1>(neighbours[2]), getRandomMovementConstraints());
            break;
        case 3: // build doorway to first and fourth neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[0]), std::get<1>(neighbours[0]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[3]), std::get<1>(neighbours[3]), getRandomMovementConstraints());
            break;
        case 4: // build doorway to second and third neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[1]), std::get<1>(neighbours[1]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[2]), std::get<1>(neighbours[2]), getRandomMovementConstraints());
            break;
        case 5: // build doorway to second and fourth neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[1]), std::get<1>(neighbours[1]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[3]), std::get<1>(neighbours[3]), getRandomMovementConstraints());
            break;
        case 6: // build doorway to third and fourth neighbour
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[2]), std::get<1>(neighbours[2]), getRandomMovementConstraints());
            _dungeonBuilder->buildDoorway(room, std::get<0>(neighbours[3]), std::get<1>(neighbours[3]), getRandomMovementConstraints());
            break;
        default:
            break;
        }
        break;
    }
}

} // namespace core
