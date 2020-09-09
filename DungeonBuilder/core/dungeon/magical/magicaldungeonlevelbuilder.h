#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include "core/dungeon/room.h"
#include "core/dungeon/dungeonlevelbuilder.h"

class MagicalDungeonLevelBuilder : DungeonLevelBuilder
{
public:
    MagicalDungeonLevelBuilder();

    void buildDungeonLevel(std::string name, int width, int height);
    void buildRoom(int id);
    void buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints);
    void buildEntrance(Room room, Room::Direction direction);
    void buildExit(Room room, Room::Direction direction);
    void buildItem(Room room);
    void buildCreature(Room room);
};

#endif // MAGICALDUNGEONLEVELBUILDER_H
