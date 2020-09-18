#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include "dungeonlevel.h"
namespace core::dungeon {

// abstract class
class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder() = default;
    virtual ~DungeonLevelBuilder(){ // TOOD: virtual on deconstructor, is this required for all descontructors
        delete _dungeonLevel;
    }

    enum class MoveConstraints : unsigned int
    {
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        DestinationLocked = 8
    };

    friend DungeonLevelBuilder::MoveConstraints operator | (DungeonLevelBuilder::MoveConstraints mc, DungeonLevelBuilder::MoveConstraints mc2){
        return static_cast<DungeonLevelBuilder::MoveConstraints>(static_cast<unsigned>(mc) | static_cast<unsigned>(mc2));
    }
    // TODO: make this right, might be better to move implementaiton to cpp file or add note for marking


    virtual void buildDungeonLevel(const std::string name, const int width, const int height){}; // WARNING: is this const?
    virtual std::shared_ptr<Room> buildRoom(const int id) const{};
    virtual void buildDoorway(const std::shared_ptr<Room> origin, const std::shared_ptr<Room> destination, const Room::Direction direction, const MoveConstraints constraints) const {};
    virtual void buildEntrance(const std::shared_ptr<Room> room, const Room::Direction direction) const {};
    virtual void buildExit(const std::shared_ptr<Room> room, const Room::Direction direction) const {};
    virtual void buildItem(const std::shared_ptr<Room> room) const {};
    virtual void buildCreature(const std::shared_ptr<Room> room) const {};
    DungeonLevel* getDungeonLevel(){
        // transfer of ownership where dungeon level is bare pointer
        // TODO: change to smart pointer, method indicates tranfer of ownership
        return _dungeonLevel;
    }


protected:
    DungeonLevel* _dungeonLevel;
};

} // namespace core::dungeon
#endif // DUNGEONLEVELBUILDER_H
