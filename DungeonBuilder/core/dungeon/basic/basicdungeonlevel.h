#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include "core/dungeon/dungeonlevel.h"

class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height){};
    std::string description() override;
};

#endif // BASICDUNGEONLEVEL_H
