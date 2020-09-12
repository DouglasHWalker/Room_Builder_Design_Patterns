#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include <iostream>
#include "core/dungeon/dungeonlevel.h"

class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel(std::string name, int width, int height);
    virtual std::string description();
};

#endif // BASICDUNGEONLEVEL_H
