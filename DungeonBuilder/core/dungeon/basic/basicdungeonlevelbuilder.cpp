#include "basicdungeonlevelbuilder.h"
#include "core/dungeon/doorway.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/creatures/monster.h"
#include "core/game.h"
#include "core/dungeon/basic/quartzchamber.h"
#include "core/dungeon/basic/rockchamber.h"

/**
 * @brief BasicDungeonLevelBuilder::buildDungeonLevel (name, width, height)—creates the appropriate concrete DungeonLevel object with the
 * given name, width, and height parameters. The object MUST be constructed as a bare pointer and NOT
 * using smart pointers.
 * @param name
 * @param width
 * @param height
 */
void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){
    _dungeonLevel = std::make_unique<DungeonLevel>(name, width, height);
}

/**
 * @brief BasicDungeonLevelBuilder::buildRoom(id)—creates a concrete Room object with the specified identifier ('id') and adds it to the
 * dungeon level currently under construction; the concrete type of Room MUST be chosen randomly
 * @param id
 */
std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int id){
    double rand = Game::instance().randomDouble();
    std::shared_ptr<Room> room;
    // create a random room from the valid room types avaliable for the type of dungeon(basic)
    if(rand <= 0.7){
        room = std::make_shared<RockChamber>(id);
    } else {
        room = std::make_shared<QuartzChamber>(id);
    }
    // add the room to the dungeon level
    _dungeonLevel->addRoom(room);

    return room;
}
void BasicDungeonLevelBuilder::buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints){
    // TODO: connect the doors to the rooms

    // create the doorways
    std::shared_ptr<Doorway> originDoorway; // origin
    std::shared_ptr<Doorway> destinationDoorway; // destination, in opposite direction
    // determine the door type
    switch (constraints) {
    case MoveConstraints::None:
        // Open doorway
        // origin
        originDoorway = std::make_shared<OpenDoorway>();
        destinationDoorway = std::make_shared<OpenDoorway>();
        break;
    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
        // one way door going from origin
        // BUG: Must fix soon.
        break;
    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)):
        // One way door going from destination

        break;
    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable) | static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
        //  Blocked doorway

        break;
    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked)):
    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked) | static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
        // Locked door on origin

    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::DestinationLocked)):
    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked) | static_cast<unsigned>(MoveConstraints::DestinationLocked)):
        // Locked Door

        break;

        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable) | static_cast<unsigned>(MoveConstraints::DestinationLocked)):
    }

    // connect doorways
    originDoorway->connect(destinationDoorway);
    destinationDoorway->connect(originDoorway);
    // set edges
    origin.setEdge(originDoorway, direction);
    // determine the opposite direction
    Room::Direction opDirection;
    switch(direction){
    case Room::Direction::North:
        opDirection = Room::Direction::South;
    case Room::Direction::South:
        opDirection = Room::Direction::North;
    case Room::Direction::East:
        opDirection = Room::Direction::West;
    case Room::Direction::West:
        opDirection = Room::Direction::North;
    }
    destination.setEdge(destinationDoorway, opDirection);


}
void BasicDungeonLevelBuilder::buildEntrance(Room room, Room::Direction direction){
    // TODO: connect the doors to the rooms
    buildDoorway(room, room, direction, MoveConstraints::OriginLocked);

}
void BasicDungeonLevelBuilder::buildExit(Room room, Room::Direction direction){
    // TODO: connect the doors to the rooms
    buildDoorway(room, room, direction, MoveConstraints::DestinationLocked);
}
void BasicDungeonLevelBuilder::buildItem(Room room){
    // TODO: prototype model Items
    double rand = Game::instance().randomDouble();
    Item *item;
    if(rand <= 0.6){
//        item = new Weapon("");
    } else {
//        item = new Consumable("");
    }
    room.setItem(item);
}
void BasicDungeonLevelBuilder::buildCreature(Room room){
    // TODO: prototype model Creatures
    // create a creatute selected randomly from the valid creature types avaliable for the type of dungeon(basic)
//    AbstractCreature *monster = new Monster(); // TODO: concrete creature
//    room.setCreature(creature);
}
