#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/creatures/monster.h"
#include "core/items/consumable.h"
#include "core/items/weapon.h"
namespace core::dungeon::magical {
/**
 * @brief The MagicalDungeonLevelBuilder class (@sa DungeonLevelBuilder) a type of dungeon level builder
 */
class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
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
    const double _CHAMBER_RARITY = 0.5;
    /**
     * @brief _CREATURE_RARITY the rarity of the most rare creature
     */
    const double _CREATURE_RARITY = 0.9;

    // Creatures
    const std::unique_ptr<core::creatures::Monster> _goblin_proto = std::make_unique<core::creatures::Monster>("Goblin");
    const std::unique_ptr<core::creatures::Monster> _evilWizard_proto = std::make_unique<core::creatures::Monster>("Evil Wizard");
    const std::unique_ptr<core::creatures::Monster> _dragon_proto = std::make_unique<core::creatures::Monster>("Dragon");
    // Weapons
    const std::unique_ptr<core::items::Weapon> _boomerang_proto = std::make_unique<core::items::Weapon>("Boomerang");
    const std::unique_ptr<core::items::Weapon> _wizardStaff_proto = std::make_unique<core::items::Weapon>("Wizard's Staff");
    const std::unique_ptr<core::items::Weapon> _magicWand_proto = std::make_unique<core::items::Weapon>("Magic Wand");
    // Consumables
    const std::unique_ptr<core::items::Consumable> _healthPotion_proto = std::make_unique<core::items::Consumable>("Health Potion");
    const std::unique_ptr<core::items::Consumable> _molotov_proto = std::make_unique<core::items::Consumable>("Molotov Cocktail");
    const std::unique_ptr<core::items::Consumable> _resistancePotion_proto = std::make_unique<core::items::Consumable>("Resistance Potion");
};

} // namespace core::dungeon::magical
#endif // MAGICALDUNGEONLEVELBUILDER_H
