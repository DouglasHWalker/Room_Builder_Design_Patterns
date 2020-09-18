#ifndef GAME_H
#define GAME_H
#include <set>
#include <ctime>
#include <random>
#include "dungeon/dungeonlevelbuilder.h"
#include "dungeon/dungeonlevel.h"
#include "dungeon/room.h"
namespace core {

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
        delete _dungeonBuilder;
    }

    void setDungeonType(core::dungeon::DungeonLevelBuilder* dungeonLevelBuilder);
    void createExampleLevel();
    void createRandomLevel(std::string name, int width, int height);
    std::vector<std::string> displayLevel();

    double randomDouble();

    // TODO: remove these somehow, not in specification
    std::string describeLevel();
    int getNumberOfRooms();
    std::string describeRoom(int roomNumber);


private:
    Game() {};
    static Game* theInstance;
    core::dungeon::DungeonLevelBuilder* _dungeonBuilder;
    core::dungeon::DungeonLevel* _dungeonLevel;

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};

    // Example constants
    const std::string _EXAMPLE_TITLE= "Example Dungeon Level";
    const int _EXAMPLE_WIDTH= 3;
    const int _EXAMPLE_HEIGHT = 3;
    // Chance constants
    const double ITEM_CHANCE = 0.35;
    const double WEAPON_CHANCE = 0.35;
    const double CREATURE_CHANCE = 0.25;
    const double TRAVERSABLE_CHANCE = 0.40;
    const double LOCKED_CHANCE = 0.30;
    const double IMPASSABLE_CHANCE = 0.30;
    // helper methods for random level generation
    std::vector<std::tuple<std::shared_ptr<core::dungeon::Room>, core::dungeon::Room::Direction>> buildNeighbours(int i, std::set<int> &builtRooms);
    core::dungeon::DungeonLevelBuilder::MoveConstraints getRandomMovementConstraints();
    void buildRandomNeighbouringDoorways(std::shared_ptr<core::dungeon::Room> room, std::vector<std::tuple<std::shared_ptr<core::dungeon::Room>, core::dungeon::Room::Direction>> neighbours);
    // TODO: double check singleton implementation correct
};

} // namespace core
#endif // GAME_H
