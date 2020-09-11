#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include <iostream>
#include "room.h"
#include "dungeonlevel.h"

// abstract class
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

    virtual void buildDungeonLevel(std::string name, int width, int height);
    virtual void buildRoom(int id);
    virtual void buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints);
    virtual void buildEntrance(Room room, Room::Direction direction);
    virtual void buildExit(Room *room, Room::Direction direction);
    virtual void buildItem(Room *room);
    virtual void buildCreature(Room *room);
    DungeonLevel* getDungeonLevel(){
        return _dungeonLevel;
    }


protected:
    DungeonLevel* _dungeonLevel;
};

#endif // DUNGEONLEVELBUILDER_H
