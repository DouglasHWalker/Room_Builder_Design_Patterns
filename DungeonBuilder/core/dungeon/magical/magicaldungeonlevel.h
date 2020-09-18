#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H
#include "core/dungeon/dungeonlevel.h"
namespace core::dungeon::magical {

class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height){}
    std::string description() const override;
};

} // namespace core::dungeon::magical
#endif // MAGICALDUNGEONLEVEL_H
