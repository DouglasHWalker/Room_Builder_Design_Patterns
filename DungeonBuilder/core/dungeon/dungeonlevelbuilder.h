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
    virtual ~DungeonLevelBuilder() = default;

    enum class MoveConstraints : unsigned int
    {
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        DestinationLocked = 8
    };
    // WARNING: add overloaded operators for the move constraints bitwise


    virtual void buildDungeonLevel(std::string name, int width, int height) const;
    virtual std::shared_ptr<Room> buildRoom(int id);
    virtual void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints);
    virtual void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction);
    virtual void buildExit(std::shared_ptr<Room> room, Room::Direction direction);
    virtual void buildItem(std::shared_ptr<Room> room);
    virtual void buildCreature(std::shared_ptr<Room> &room);
    std::unique_ptr<DungeonLevel> getDungeonLevel(){
        // transfer of ownership where dungeon level is bare pointer
        // TODO: change to smart pointer, method indicates tranfer of ownership
        return std::move(_dungeonLevel);
    }


protected:
    std::unique_ptr<DungeonLevel> _dungeonLevel;
};

#endif // DUNGEONLEVELBUILDER_H
