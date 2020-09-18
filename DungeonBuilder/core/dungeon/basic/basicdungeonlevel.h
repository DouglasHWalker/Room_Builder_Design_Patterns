#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include <sstream>
#include "core/dungeon/dungeonlevel.h"
namespace core::dungeon::basic {

class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height){
        std::stringstream ss;
        ss << name << "\nSize: " << width << " x " << height << "\nType: Dark Cave (Basic Dungeon)";
        _description = ss.str();
    };
    std::string description() override;
};

} // namespace core::dungeon::basic
#endif // BASICDUNGEONLEVEL_H
