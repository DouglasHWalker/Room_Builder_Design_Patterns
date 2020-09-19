#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include "dungeonlevel.h"
namespace core::dungeon {
/**
 * @brief The DungeonLevelBuilder class the base class for all the types of
 * dungeon level builders in the game. A dungeon level builder is resposnsible
 * for building the components of the dungeon level (rooms, doorways, entry,
 * exit, item, creature and the dungeon level itself.
 */
class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder() = default;
    virtual ~DungeonLevelBuilder() {
        delete _dungeonLevel;
    }
    /**
     * @brief The MoveConstraints enum represents the range of possible movement types for a given doorway in both directions.
     */
    enum class MoveConstraints : unsigned int { None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 8 };
    friend DungeonLevelBuilder::MoveConstraints operator | (DungeonLevelBuilder::MoveConstraints mc, DungeonLevelBuilder::MoveConstraints mc2);

    /**
     * @brief buildDungeonLevel build the dungeon level based on the given name, width and height
     * @param name of the dungeon level
     * @param width of the dungeon level
     * @param height of the dungeon level
     */
    virtual void buildDungeonLevel(const std::string &name, const int width, const int height) {};
    /**
     * @brief buildRoom build a random room and all of its wall, add the room to the dungeon level
     * @param id the room's identification
     * @return the built room
     */
    virtual std::shared_ptr<Room> buildRoom(const int id) const {};
    /**
     * @brief buildDoorway build a doorway between the origin room and the destination room with the given movement constraints
     * @param origin the starting room
     * @param destination the destination room
     * @param direction the direction of travel from the origin room to the destination room
     * @param constraints the movement constraints to abide by
     */
    virtual void buildDoorway(const std::shared_ptr<Room> origin, const std::shared_ptr<Room> destination,
                              const Room::Direction &direction, const MoveConstraints &constraints) const {};
    /**
     * @brief buildEntrance build the entrance to the dungeon level, add the entrance to
     * the given room and in the given direction.
     * @param room the room to add the entrance to
     * @param direction the direction to add the entrance to in the room
     */
    virtual void buildEntrance(const std::shared_ptr<Room> room, const Room::Direction &direction) const {};
    /**
     * @brief buildExit build the exit to the dungeon level, add the exit to the given room
     * and in the given direction, set the rooms creature to a boss
     * @param room the room to add the exit to
     * @param direction the direction to add the exit to in the room
     */
    virtual void buildExit(const std::shared_ptr<Room> room, const Room::Direction &direction) const {};
    /**
     * @brief buildItem build and add a random item to the given room
     * @param room the room to build the item in
     */
    virtual void buildItem(const std::shared_ptr<Room> room) const {};
    /**
     * @brief buildCreature build and add a random creature to the given room
     * @param room the room to build the creture in
     */
    virtual void buildCreature(const std::shared_ptr<Room> room) const {};
    DungeonLevel* getDungeonLevel() {
        return _dungeonLevel;
    }

protected:
    DungeonLevel* _dungeonLevel;
};

} // namespace core::dungeon
#endif // DUNGEONLEVELBUILDER_H
