#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include <memory>
#include "core/dungeon/room.h"
#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/dungeon/magical/magicaldungeonlevel.h"

class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    void buildDungeonLevel(std::string name, int width, int height); // WARNING: is this const?
    std::shared_ptr<Room> buildRoom(int id);
    void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints);
    void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction);
    void buildExit(std::shared_ptr<Room> room, Room::Direction direction);
    void buildItem(std::shared_ptr<Room> room);
    void buildCreature(std::shared_ptr<Room> room);
private:
    double _ITEM_RARITY = 0.5;
    double _CHAMBER_RARITY = 0.5;
};

#endif // MAGICALDUNGEONLEVELBUILDER_H
