#include "magicaldungeonlevelbuilder.h"
#include "core/game.h"
#include "core/dungeon/doorway.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/creatures/monster.h"
#include "core/dungeon/magical/alchemistslaboratory.h"
#include "core/dungeon/magical/enchantedlibrary.h"
/**
 * @brief BasicDungeonLevelBuilder::buildDungeonLevel (name, width, height)—creates the appropriate concrete DungeonLevel object with the
 * given name, width, and height parameters. The object MUST be constructed as a bare pointer and NOT
 * using smart pointers.
 * @param name
 * @param width
 * @param height
 */
void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){
    _dungeonLevel = new MagicalDungeonLevel(name, width, height); // NOTE: Must use bare pointer
}

/**
 * @brief BasicDungeonLevelBuilder::buildRoom(id)—creates a concrete Room object with the specified identifier ('id') and adds it to the
 * dungeon level currently under construction; the concrete type of Room MUST be chosen randomly
 * @param id
 */
std::shared_ptr<Room> MagicalDungeonLevelBuilder::buildRoom(int id){
    double rand = Game::instance()->randomDouble();
    std::shared_ptr<Room> room;
    // create a random room from the valid room types avaliable for the type of dungeon(basic)
    if(rand <= _CHAMBER_RARITY){
        room = std::make_shared<EnchantedLibrary>(id);
    } else {
        room = std::make_shared<AlchemistsLaboratory>(id);
    }
    // add the room to the dungeon level
    _dungeonLevel->addRoom(room);

    return room;
}
void MagicalDungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints){
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
        break;
    }

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
void MagicalDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction){
    // TODO: connect the doors to the rooms
    buildDoorway(room, room, direction, MoveConstraints::OriginLocked);

}
void MagicalDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction){
    // TODO: connect the doors to the rooms
    buildDoorway(room, room, direction, MoveConstraints::DestinationLocked);
    std::unique_ptr<AbstractCreature> creature = room->creature();
    creature->setIsBoss();
    room->setCreature(std::move(creature));
    // TODO: transfer of ownership might be avoidable here...
}
void MagicalDungeonLevelBuilder::buildItem(std::shared_ptr<Room> room){
    double rand = Game::instance()->randomDouble();
    std::unique_ptr<Item> item;
    // TOOD: make this more extensible, the randomisation automatic or something
    if(rand <= _ITEM_RARITY){
        if(rand <= _ITEM_RARITY/3){
            item = _boomerang_proto->clone();
        } else if(rand <= (_ITEM_RARITY/3)*2){
            item = _magicWand_proto->clone();
        } else {
            item = _wizardStaff_proto->clone();
        }
    } else {
        // randomly select a prototype
        if(rand <= _ITEM_RARITY/3){
            item = _molotov_proto->clone();
        } else if(rand <= (_ITEM_RARITY/3)*2){
            item = _healthPotion_proto->clone();
        } else {
            item = _resistancePotion_proto->clone();
        }
    }
    room->setItem(std::move(item));
}
void MagicalDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room){
    double rand = Game::instance()->randomDouble();
    std::unique_ptr<AbstractCreature> creature;
    if(rand >= _CREATURE_RARITY){
        creature = _dragon_proto->clone();
    } else if(rand <= _CREATURE_RARITY/2){
        creature = _evilWizard_proto->clone();
    } else {
        creature = _goblin_proto->clone();
    }
    room->setCreature(std::move(creature));
}
