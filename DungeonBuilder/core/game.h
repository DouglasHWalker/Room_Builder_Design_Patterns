#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <random>
#include "dungeon/dungeonlevelbuilder.h"

class Game
{
public:
    static Game& instance();
    Game(Game &other) = delete;
    Game operator=(Game &other) = delete;

    void setDungeonType(DungeonLevelBuilder dungeonLevelBuilder);
    void createExampleLevel();
    void createRandomLevel(std::string name, int width, int height);
    void displayLevel();
    double randomDouble();
private:
    Game();
    static Game theInstance;

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};
};

#endif // GAME_H
