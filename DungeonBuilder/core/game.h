#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <random>
#include "dungeon/dungeonlevelbuilder.h"

class Game
{
public:
    static Game* instance(){
        if(theInstance == nullptr){
            theInstance = new Game;
        }
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

    // TODO: remove these somehow, not in specification
    std::string describeLevel();
    int getNumberOfRooms();
    std::string describeRoom(int roomNumber);


private:
    Game() { std::cout << "Game created"; };
    static Game* theInstance;
    std::shared_ptr<DungeonLevelBuilder> _dungeonBuilder;
    DungeonLevel* _dungeonLevel;

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};

    // Chance constants
    const double ITEM_CHANCE = 0.35;
    const double WEAPON_CHANCE = 0.35;
    const double CREATURE_CHANCE = 0.25;
    const double TRAVERSABLE_CHANCE = 0.4;
    const double LOCKED_CHANCE = 0.3;
    const double IMPASSABLE_CHANCE = 0.3;
    // helper methods for random level generation
    void addRandomDoorways(int row, int col, std::shared_ptr<Room> room);
    void buildRandomDoorway(double random, Room::Direction direction);
    void buildRandomEntry(Room::Direction direction);
    void buildRandomExit(Room::Direction direction);
    // TODO: double check singleton implementation correct
};

#endif // GAME_H
