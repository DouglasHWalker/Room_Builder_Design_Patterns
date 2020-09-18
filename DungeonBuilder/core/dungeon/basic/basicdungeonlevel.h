#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include "core/dungeon/dungeonlevel.h"
namespace core::dungeon::basic {

class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel(const std::string &name, const int width, const int height)
        : DungeonLevel(name, width, height) {}
    std::string description() const override;
};

} // namespace core::dungeon::basic
#endif // BASICDUNGEONLEVEL_H
