#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include "dungeonlevel.h"
namespace core::dungeon {

// abstract class
class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder() = default;
    virtual ~DungeonLevelBuilder() {
        delete _dungeonLevel;
    }

    enum class MoveConstraints : unsigned int { None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 8 };
    friend DungeonLevelBuilder::MoveConstraints operator | (DungeonLevelBuilder::MoveConstraints mc, DungeonLevelBuilder::MoveConstraints mc2);

    virtual void buildDungeonLevel(const std::string &name, const int width, const int height) {};
    virtual std::shared_ptr<Room> buildRoom(const int id) const {};
    virtual void buildDoorway(const std::shared_ptr<Room> origin, const std::shared_ptr<Room> destination,
                              const Room::Direction &direction, const MoveConstraints &constraints) const {};
    virtual void buildEntrance(const std::shared_ptr<Room> room, const Room::Direction &direction) const {};
    virtual void buildExit(const std::shared_ptr<Room> room, const Room::Direction &direction) const {};
    virtual void buildItem(const std::shared_ptr<Room> room) const {};
    virtual void buildCreature(const std::shared_ptr<Room> room) const {};
    DungeonLevel* getDungeonLevel() {
        return _dungeonLevel;
    }

protected:
    DungeonLevel* _dungeonLevel;
};

} // namespace core::dungeon
#endif // DUNGEONLEVELBUILDER_H
