#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <random>
#include "dungeon/dungeonlevelbuilder.h"

class Game
{
public:
    static std::shared_ptr<Game> instance(){
        return theInstance; // TODO: should this be a smart pointer
    }
    Game(Game &other) = delete;
    Game operator=(Game &other) = delete;
    ~Game(){
        delete _dungeonLevel; // TODO: double check this is a correctly deleted bare pointer
    }

    void setDungeonType(std::shared_ptr<DungeonLevelBuilder> dungeonLevelBuilder);
    void createExampleLevel();
    void createRandomLevel(std::string name, int width, int height);
    std::vector<std::string> displayLevel();
    double randomDouble();
private:
    Game() { std::cout << "Game created"; };
    static std::shared_ptr<Game> theInstance;
    DungeonLevelBuilder* _dungeonBuilder;
    DungeonLevel* _dungeonLevel;

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};

    // TODO: double check singleton implementation correct
};

#endif // GAME_H
