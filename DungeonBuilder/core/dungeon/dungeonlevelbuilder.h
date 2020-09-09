#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include <iostream>
#include "room.h"
#include "dungeonlevel.h"

class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder();

    enum class MoveConstraints : unsigned int
    {
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        DestinationLocked = 8
    };

    void buildDungeonLevel(std::string name, int width, int height);
    void buildRoom(int id);
    void buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints);
    void buildEntrance(Room room, Room::Direction direction);
    void buildExit(Room room, Room::Direction direction);
    void buildItem(Room room);
    void buildCreature(Room room);
    DungeonLevel getDungeonLevel();


private:
    DungeonLevel _dungeonLevel;
};

#endif // DUNGEONLEVELBUILDER_H
