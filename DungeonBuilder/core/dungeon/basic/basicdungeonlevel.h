#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include "core/dungeon/dungeonlevel.h"
namespace core::dungeon::basic {

class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height){}
    std::string description() const override;
};

} // namespace core::dungeon::basic
#endif // BASICDUNGEONLEVEL_H
