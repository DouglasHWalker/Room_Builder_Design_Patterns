#include "magicaldungeonlevelbuilder.h"
#include "core/game.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/dungeon/common/onewaydoor.h"
#include "core/dungeon/common/lockeddoor.h"
#include "core/dungeon/common/blockeddoorway.h"
#include "core/dungeon/magical/magicaldungeonlevel.h"
#include "core/dungeon/magical/alchemistslaboratory.h"
#include "core/dungeon/magical/enchantedlibrary.h"
#include "core/dungeon/magical/magicwall.h"
namespace core::dungeon::magical {

using namespace core::dungeon::common;
using core::dungeon::RoomEdge;
using core::items::Item;
using core::creatures::AbstractCreature;

void MagicalDungeonLevelBuilder::buildDungeonLevel(const std::string name, const int width, const int height){
    _dungeonLevel = new MagicalDungeonLevel(name, width, height); // NOTE: Must use bare pointer
}

std::shared_ptr<Room> MagicalDungeonLevelBuilder::buildRoom(int id)  const{
    double rand = Game::instance()->randomDouble();
    std::shared_ptr<Room> room;
    // create a random room from the valid room types avaliable for the type of dungeon(basic)
    if(rand <= _CHAMBER_RARITY){
        room = std::make_shared<EnchantedLibrary>(id);
    } else {
        room = std::make_shared<AlchemistsLaboratory>(id);
    }
    // build the walls of the room
    room->setEdge(std::make_shared<MagicWall>(Room::Direction::North), Room::Direction::North);
    room->setEdge(std::make_shared<MagicWall>(Room::Direction::South), Room::Direction::South);
    room->setEdge(std::make_shared<MagicWall>(Room::Direction::East), Room::Direction::East);
    room->setEdge(std::make_shared<MagicWall>(Room::Direction::West), Room::Direction::West);
    // add the room to the dungeon level
    _dungeonLevel->addRoom(room);

    return room;
}

void MagicalDungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints) const{
    // if doorway does not already exist here
    if(not origin->edgeAt(direction)->isPassage()){// the doorways to build
        std::shared_ptr<Doorway> originDoorway; // origin
        std::shared_ptr<Doorway> destinationDoorway; // destination, in opposite direction
        // determine the door type
        switch (constraints) {
        case MoveConstraints::None:
            // Open doorway
            originDoorway = std::make_shared<OpenDoorway>(direction);
            destinationDoorway = std::make_shared<OpenDoorway>(!direction);
            break;
        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)):
            // Origin doorway cannot be passed through.
            originDoorway = std::make_shared<OneWayDoor>(direction);
            destinationDoorway = std::make_shared<OpenDoorway>(!direction);
            break;
        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
            // Destination doorway cannot be passed through.
            originDoorway = std::make_shared<OpenDoorway>(direction);
            destinationDoorway = std::make_shared<OneWayDoor>(!direction);
            break;
        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable) | static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
            //  Blocked doorway on both ends
            originDoorway = std::make_shared<BlockedDoorway>();
            destinationDoorway = std::make_shared<BlockedDoorway>();
            break;
        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked)):
            // Locked door on origin
            originDoorway = std::make_shared<LockedDoor>();
            // opendoor on destination
            destinationDoorway = std::make_shared<OpenDoorway>(!direction);
            break;
        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked) | static_cast<unsigned>(MoveConstraints::DestinationImpassable)):
            // Locked door on origin
            originDoorway = std::make_shared<LockedDoor>();
            // Destination doorway cannot be passed through.
            destinationDoorway = std::make_shared<OneWayDoor>(!direction);
            break;
        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::DestinationLocked)):
            // origin opened
            originDoorway = std::make_shared<OpenDoorway>(direction);
            // destination locked
            destinationDoorway = std::make_shared<LockedDoor>();
            break;
        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable) | static_cast<unsigned>(MoveConstraints::DestinationLocked)):
            // Origin doorway cannot be passed through.
            originDoorway = std::make_shared<OneWayDoor>(direction);
            // destination locked
            destinationDoorway = std::make_shared<LockedDoor>();
            break;
        case static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked) | static_cast<unsigned>(MoveConstraints::DestinationLocked)):
            // Locked Door origin and destination
            originDoorway = std::make_shared<LockedDoor>();
            destinationDoorway = std::make_shared<LockedDoor>();
            break;
        default:
            break;
        }
        // connect doorways in both directions
        originDoorway->connect(destinationDoorway.get()); // WARNING: getting bare pointer
        destinationDoorway->connect(originDoorway.get());
        // set edges in both directions
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, !direction);
    }
}

void MagicalDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction) const{
    // build entry
    std::shared_ptr<Doorway> entry = std::make_shared<OneWayDoor>(direction);
    entry->setEntry(true);
    // set edge of room
    room->setEdge(entry, direction);
}

void MagicalDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction) const{
    // build exit
    std::shared_ptr<Doorway> exit =  std::make_shared<OneWayDoor>(direction);
    exit->setExit(true);
    // set edge of room
    room->setEdge(exit, direction);

    // set creature to boss
    std::unique_ptr<AbstractCreature> creature = room->creature();
    // make sure creature exists
    if(creature != nullptr){ creature->setIsBoss(); }
    // transfer ownership back to creature
    room->setCreature(std::move(creature));
    // TODO: transfer of ownership might be avoidable here...
}

void MagicalDungeonLevelBuilder::buildItem(std::shared_ptr<Room> room) const{
    double rand = Game::instance()->randomDouble();
    std::unique_ptr<Item> item;
    int randItem = std::rand() % 3;
    if(rand <= _WEAPON_CHANCE){ // weapon
        switch (randItem) {
        case 0: item = _boomerang_proto->clone(); // ~33% chance
            break;
        case 1: item = _magicWand_proto->clone(); // ~33% chance
            break;
        case 2: item = _wizardStaff_proto->clone(); // ~33% chance
            break;
        }
    } else { // Consumable
        switch (randItem) {
        case 0: item = _molotov_proto->clone(); // ~33% chance
            break;
        case 1: item = _healthPotion_proto->clone(); // ~33% chance
            break;
        case 2: item = _resistancePotion_proto->clone(); // ~33% chance
            break;
        }
    }
    room->setItem(std::move(item));
}
void MagicalDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room){
    std::unique_ptr<AbstractCreature> creature;
    int randCreature = std::rand() % 6;
    switch (randCreature) {
    case 0:
        creature = _dragon_proto->clone(); // ~16% chance
        break;
    case 1:
    case 2:
        creature = _evilWizard_proto->clone(); // ~32% chance
        break;
    default: creature = _goblin_proto->clone(); // ~52% chance
        break;
    }
    room->setCreature(std::move(creature));
}

} // namespace core::dungeon::magical
