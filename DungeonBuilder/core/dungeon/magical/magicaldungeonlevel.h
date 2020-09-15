#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H
#include "core/dungeon/dungeonlevel.h"

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

#endif // MAGICALDUNGEONLEVEL_H
