#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include <memory>
#include "core/dungeon/room.h"
#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/dungeon/magical/magicaldungeonlevel.h"
#include "core/creatures/monster.h"
#include "core/items/consumable.h"
#include "core/items/weapon.h"

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
    double _CREATURE_RARITY = 0.9;

    // Creatures
    std::unique_ptr<Monster> _goblin_proto = std::make_unique<Monster>("Goblin");
    std::unique_ptr<Monster> _evilWizard_proto = std::make_unique<Monster>("Evil Wizard");
    std::unique_ptr<Monster> _dragon_proto = std::make_unique<Monster>("Dragon");
    // FIXME: make boss prototype? may or may not, 15.09: probably not, should be easier to randomise that way
    // Weapons
    std::unique_ptr<Weapon> _boomerang_proto = std::make_unique<Weapon>("Boomerang");
    std::unique_ptr<Weapon> _wizardStaff_proto = std::make_unique<Weapon>("Wizard's Staff");
    std::unique_ptr<Weapon> _magicWand_proto = std::make_unique<Weapon>("Magic Wand");
    // Consumables
    std::unique_ptr<Consumable> _healthPotion_proto = std::make_unique<Consumable>("Health Potion");
    std::unique_ptr<Consumable> _molotov_proto = std::make_unique<Consumable>("Molotov Cocktail");
    std::unique_ptr<Consumable> _resistancePotion_proto = std::make_unique<Consumable>("Resistance Potion");
};

#endif // MAGICALDUNGEONLEVELBUILDER_H
