#include "basicdungeonlevelbuilder.h"
#include "core/dungeon/doorway.h"
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
    _dungeonLevel = new DungeonLevel(name, width, height);
}

/**
 * @brief BasicDungeonLevelBuilder::buildRoom(id)—creates a concrete Room object with the specified identifier ('id') and adds it to the
 * dungeon level currently under construction; the concrete type of Room MUST be chosen randomly
 * @param id
 */
Room BasicDungeonLevelBuilder::buildRoom(int id){
    double rand = Game::instance().randomDouble();
    Room *room;
    // create a random room from the valid room types avaliable for the type of dungeon(basic)
    if(rand <= 0.7){
        room = new RockChamber(id);
    } else {
        room = new QuartzChamber(id);
    }
    // add the room to the dungeon level
    _dungeonLevel->addRoom(room);
}
void BasicDungeonLevelBuilder::buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints){
    // TODO: connect the doors to the rooms
    Doorway *originDoorway = new Doorway(); // origin
    Doorway *destinationDoorway = new Doorway(); // destination, in opposite direction
    // adding contraints
}
void BasicDungeonLevelBuilder::buildEntrance(Room room, Room::Direction direction){
    // TODO: connect the doors to the rooms
    buildDoorway(room, room, direction, MoveConstraints::OriginLocked); // TODO: make sure this is right

}
void BasicDungeonLevelBuilder::buildExit(Room room, Room::Direction direction){
    // TODO: connect the doors to the rooms
    buildDoorway(room, room, direction, MoveConstraints::DestinationLocked); // TODO: make sure this is right
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
