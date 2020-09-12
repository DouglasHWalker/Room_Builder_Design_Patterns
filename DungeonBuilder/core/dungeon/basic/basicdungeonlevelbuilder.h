#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H
#include "core/dungeon/room.h"
#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/dungeon/basic/basicdungeonlevel.h"


class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    void buildDungeonLevel(std::string name, int width, int height);
    Room buildRoom(int id);
    void buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints);
    void buildEntrance(Room room, Room::Direction direction);
    void buildExit(Room room, Room::Direction direction);
    void buildItem(Room room);
    void buildCreature(Room room);
};

#endif // BASICDUNGEONLEVELBUILDER_H
