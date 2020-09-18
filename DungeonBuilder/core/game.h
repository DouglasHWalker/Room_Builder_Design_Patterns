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
        return theInstance;
    }
    Game(Game &other) = delete;
    Game operator=(Game &other) = delete;
    ~Game(){
        delete _dungeonLevel;
        delete _dungeonBuilder;
        delete theInstance;
    }

    void setDungeonType(core::dungeon::DungeonLevelBuilder* dungeonLevelBuilder);
    void createExampleLevel();
    void createRandomLevel(const std::string &name, const int width, const int height);
    std::vector<std::string> displayLevel() const;

    double randomDouble(); // non-const, changes private memeber _randomGenerator

    // TODO: remove these somehow, not in specification
    std::string describeLevel() const;
    int getNumberOfRooms() const;
    std::string describeRoom(const int roomNumber) const;


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
    std::vector<std::tuple<std::shared_ptr<core::dungeon::Room>, core::dungeon::Room::Direction>> buildNeighbours(const int i, std::set<int> &builtRooms) const;
    core::dungeon::DungeonLevelBuilder::MoveConstraints getRandomMovementConstraints(); // non-const changes _randomGenerator
    void buildRandomNeighbouringDoorways(std::shared_ptr<core::dungeon::Room> room, std::vector<std::tuple<std::shared_ptr<core::dungeon::Room> , core::dungeon::Room::Direction>> &neighbours);  // non-const changes _randomGenerator
};

} // namespace core
#endif // GAME_H
