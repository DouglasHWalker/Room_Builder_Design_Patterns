#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H
#include <memory>
#include "core/dungeon/room.h"
#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/dungeon/basic/basicdungeonlevel.h"
#include "core/creatures/monster.h"


class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    void buildDungeonLevel(std::string name, int width, int height);
    std::shared_ptr<Room> buildRoom(int id);
    void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints);
    void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction);
    void buildExit(std::shared_ptr<Room> room, Room::Direction direction);
    void buildItem(std::shared_ptr<Room> room);
    void buildCreature(std::shared_ptr<Room> room);
private:
    double _ITEM_RARITY = 0.6;
    double _CHAMBER_RARITY = 0.7;

    std::unique_ptr<Monster> _goblin_proto = std::make_unique<Monster>("Goblin");
    std::unique_ptr<Monster> _werewolf_proto = std::make_unique<Monster>("Werewolf");
    std::unique_ptr<Monster> _evilWizard_proto = std::make_unique<Monster>("Evil Wizard");
    std::unique_ptr<Monster> _dragon_proto = std::make_unique<Monster>("Dragon");
    // FIXME: make boss prototype? may or may not

};

#endif // BASICDUNGEONLEVELBUILDER_H
