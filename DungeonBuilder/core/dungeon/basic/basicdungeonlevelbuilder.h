#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H
#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/creatures/monster.h"
#include "core/items/consumable.h"
#include "core/items/weapon.h"

namespace core::dungeon::basic {

using core::creatures::Monster;
using core::items::Weapon;
using core::items::Consumable;

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
    double _WEAPON_CHANCE = 0.35;
    double _CHAMBER_RARITY = 0.7;
    double _CREATURE_RARITY = 0.75;

    // Creatures
    std::unique_ptr<Monster> _goblin_proto = std::make_unique<Monster>("Goblin");
    std::unique_ptr<Monster> _werewolf_proto = std::make_unique<Monster>("Werewolf");
    std::unique_ptr<Monster> _evilWizard_proto = std::make_unique<Monster>("Evil Wizard");
    // Weapons
    std::unique_ptr<Weapon> _boomerang_proto = std::make_unique<Weapon>("Boomerang");
    std::unique_ptr<Weapon> _shortSword_proto = std::make_unique<Weapon>("Short Sword");
    std::unique_ptr<Weapon> _battleAxe_proto = std::make_unique<Weapon>("Battle Axe");
    // Consumables
    std::unique_ptr<Consumable> _healthPotion_proto = std::make_unique<Consumable>("Health Potion");
    std::unique_ptr<Consumable> _molotov_proto = std::make_unique<Consumable>("Molotov Cocktail");
    std::unique_ptr<Consumable> _smokeBomb_proto = std::make_unique<Consumable>("Smoke Bomb");
};

} // namespace core::dungeon::basic
#endif // BASICDUNGEONLEVELBUILDER_H
