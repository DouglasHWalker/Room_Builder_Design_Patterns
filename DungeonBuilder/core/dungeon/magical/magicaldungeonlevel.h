#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H
#include "core/dungeon/dungeonlevel.h"

class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height){};
    std::string description() override;
};

#endif // MAGICALDUNGEONLEVEL_H
