#include "dungeonlevelbuilder.h"
namespace core::dungeon {

DungeonLevelBuilder::MoveConstraints operator | (DungeonLevelBuilder::MoveConstraints mc, DungeonLevelBuilder::MoveConstraints mc2){
    return static_cast<DungeonLevelBuilder::MoveConstraints>(static_cast<unsigned>(mc) | static_cast<unsigned>(mc2));
}

} // namespace core::dungeon
