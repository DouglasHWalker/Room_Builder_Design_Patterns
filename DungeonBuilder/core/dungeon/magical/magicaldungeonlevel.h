#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H
#include <sstream>
#include "core/dungeon/dungeonlevel.h"
namespace core::dungeon::magical {

class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height){
        std::stringstream ss;
        ss << name << "\nSize: " << width << " x " << height << "\nType: Dragons Den (Magical Dungeon)";
        _description = ss.str();
        };
    std::string description() override;
};

} // namespace core::dungeon::magical
#endif // MAGICALDUNGEONLEVEL_H
