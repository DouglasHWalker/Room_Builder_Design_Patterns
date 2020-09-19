#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H
#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/creatures/monster.h"
#include "core/items/consumable.h"
#include "core/items/weapon.h"

namespace core::dungeon::basic {
/**
 * @brief The BasicDungeonLevelBuilder class (@sa DungeonLevelBuilder) a type of dungeon level builder
 */
class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    void buildDungeonLevel(const std::string &name, const int width, const int height) override;
    std::shared_ptr<Room> buildRoom(const int id) const override;
    void buildDoorway(const std::shared_ptr<Room> origin, const std::shared_ptr<Room> destination,
                      const Room::Direction &direction, const MoveConstraints &constraints) const override;
    void buildEntrance(const std::shared_ptr<Room> room, const Room::Direction &direction) const override;
    void buildExit(const std::shared_ptr<Room> room, const Room::Direction &direction) const override;
    void buildItem(const std::shared_ptr<Room> room) const override;
    void buildCreature(const std::shared_ptr<Room> room) const override;
private:
    /**
     * @brief _WEAPON_CHANCE the chance that an item will be a weapon
     */
    const double _WEAPON_CHANCE = 0.35;
    /**
     * @brief _CHAMBER_RARITY the rarity of the most rare room type
     */
    const double _CHAMBER_RARITY = 0.7;
    /**
     * @brief _CREATURE_RARITY the rarity of the most rare creature
     */
    const double _CREATURE_RARITY = 0.75;

    // Creatures
    const std::unique_ptr<core::creatures::Monster> _goblin_proto = std::make_unique<core::creatures::Monster>("Goblin");
    const std::unique_ptr<core::creatures::Monster> _werewolf_proto = std::make_unique<core::creatures::Monster>("Werewolf");
    const std::unique_ptr<core::creatures::Monster> _evilWizard_proto = std::make_unique<core::creatures::Monster>("Evil Wizard");
    // Weapons
    const std::unique_ptr<core::items::Weapon> _boomerang_proto = std::make_unique<core::items::Weapon>("Boomerang");
    const std::unique_ptr<core::items::Weapon> _shortSword_proto = std::make_unique<core::items::Weapon>("Short Sword");
    const std::unique_ptr<core::items::Weapon> _battleAxe_proto = std::make_unique<core::items::Weapon>("Battle Axe");
    // Consumables
    const std::unique_ptr<core::items::Consumable> _healthPotion_proto = std::make_unique<core::items::Consumable>("Health Potion");
    const std::unique_ptr<core::items::Consumable> _molotov_proto = std::make_unique<core::items::Consumable>("Molotov Cocktail");
    const std::unique_ptr<core::items::Consumable> _smokeBomb_proto = std::make_unique<core::items::Consumable>("Smoke Bomb");
};

} // namespace core::dungeon::basic
#endif // BASICDUNGEONLEVELBUILDER_H
