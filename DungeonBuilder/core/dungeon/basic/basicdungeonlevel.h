#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include "core/dungeon/dungeonlevel.h"

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

#endif // BASICDUNGEONLEVEL_H
