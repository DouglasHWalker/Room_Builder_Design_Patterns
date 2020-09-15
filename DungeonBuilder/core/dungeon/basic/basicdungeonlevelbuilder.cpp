#include "basicdungeonlevelbuilder.h"
#include "core/game.h"
#include "core/dungeon/doorway.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/dungeon/basic/quartzchamber.h"
#include "core/dungeon/basic/rockchamber.h"
#include "core/dungeon/basic/rockwall.h"
#include "core/creatures/monster.h"

/**
 * @brief BasicDungeonLevelBuilder::buildDungeonLevel (name, width, height)—creates the appropriate concrete DungeonLevel object with the
 * given name, width, and height parameters. The object MUST be constructed as a bare pointer and NOT
 * using smart pointers.
 * @param name
 * @param width
 * @param height
 */
void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){
    _dungeonLevel = new BasicDungeonLevel(name, width, height); // NOTE: Must use bare pointer
}

/**
 * @brief BasicDungeonLevelBuilder::buildRoom(id)—creates a concrete Room object with the specified identifier ('id') and adds it to the
 * dungeon level currently under construction; the concrete type of Room MUST be chosen randomly
 * @param id
 */
std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int id){
    double rand = Game::instance()->randomDouble();
    std::shared_ptr<Room> room;
    // create a random room from the valid room types avaliable for the type of dungeon(basic)
    if(rand <= _CHAMBER_RARITY){
        room = std::make_shared<RockChamber>(id);
    } else {
        room = std::make_shared<QuartzChamber>(id);
    }
    // build the walls of the room
    room->setEdge(std::make_shared<RockWall>(), Room::Direction::North);
    room->setEdge(std::make_shared<RockWall>(), Room::Direction::South);
    room->setEdge(std::make_shared<RockWall>(), Room::Direction::East);
    room->setEdge(std::make_shared<RockWall>(), Room::Direction::West);
    // add the room to the dungeon level
    _dungeonLevel->addRoom(room);

    return room;
}
void BasicDungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints){
    // TODO: connect the doors to the rooms

    // create the doorways
    std::shared_ptr<Doorway> originDoorway; // origin
    std::shared_ptr<Doorway> destinationDoorway; // destination, in opposite direction
    // determine the door type
    originDoorway = std::make_shared<OpenDoorway>();
    destinationDoorway = std::make_shared<OpenDoorway>();
//    switch (constraints) {
//    case MoveConstraints::None:
//        // Open doorway
//        // origin
//        originDoorway = std::make_shared<OpenDoorway>();
//        destinationDoorway = std::make_shared<OpenDoorway>();
//        break;
//    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
//        // one way door going from origin
//        // BUG: Must fix soon.
//        break;
//    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)):
//        // One way door going from destination

//        break;
//    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable) | static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
//        //  Blocked doorway

//        break;
//    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked)):
//    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked) | static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
//        // Locked door on origin

//    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::DestinationLocked)):
//    case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked) | static_cast<unsigned>(MoveConstraints::DestinationLocked)):
//        // Locked Door

//        break;

//        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable) | static_cast<unsigned>(MoveConstraints::DestinationLocked)):
//        break;
//    }

    // connect doorways
    originDoorway->connect(destinationDoorway);
    destinationDoorway->connect(originDoorway);
    // set edges
    origin->setEdge(originDoorway, direction);
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
    destination->setEdge(destinationDoorway, opDirection);


}
void BasicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room>  room, Room::Direction direction){
    buildDoorway(room, room, direction, MoveConstraints::OriginLocked);

}
void BasicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction){
    buildDoorway(room, room, direction, MoveConstraints::DestinationLocked);
    std::unique_ptr<AbstractCreature> creature = room->creature();
    creature->setIsBoss();
    room->setCreature(std::move(creature));
    // TODO: transfer of ownership might be avoidable here...
}
void BasicDungeonLevelBuilder::buildItem(std::shared_ptr<Room> room){
    // TODO: prototype model Items
    double rand = Game::instance()->randomDouble();
    std::unique_ptr<Item> item;
    if(rand <= _ITEM_RARITY){
        if(rand <= _ITEM_RARITY/3){
            item = std::unique_ptr(_boomerang_proto->clone());
        } else if(rand <= (_ITEM_RARITY/3)*2){
            item = std::unique_ptr(_battleAxe_proto->clone());
        } else {
            item = std::unique_ptr(_shortSword_proto->clone());
        }
    } else {
        // TOOD: make this more extensible
        // randomly select a prototype
        if(rand <= _ITEM_RARITY/3){
            item = std::unique_ptr(_molotov_proto->clone());
        } else if(rand <= (_ITEM_RARITY/3)*2){
            item = std::unique_ptr(_healthPotion_proto->clone());
        } else {
            item = std::unique_ptr(_smokeBomb_proto->clone());
        }
    }
    room->setItem(std::move(item));
}
void BasicDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room){
    double rand = Game::instance()->randomDouble();
    std::unique_ptr<AbstractCreature> creature;
    if(rand >= _CREATURE_RARITY){
        creature = _werewolf_proto->clone();
    } else if(rand <= _CREATURE_RARITY/2){
        creature = _evilWizard_proto->clone();
    } else {
        creature = _goblin_proto->clone();
    }
    room->setCreature(std::move(creature));
}
