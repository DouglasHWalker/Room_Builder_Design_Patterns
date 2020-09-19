#ifndef GAME_H
#define GAME_H
#include <set>
#include <ctime>
#include <random>
#include "dungeon/dungeonlevelbuilder.h"
#include "dungeon/dungeonlevel.h"
#include "dungeon/room.h"
namespace core {
/**
 * @brief The Game class directs the DungeonLevelBuilders to build dungeonLevels and their components.
 * handles the randomisation logic for building random dungeon levels, contains the exampledungeonlevel
 * recipe for building the exampledungeonlevel
 */
class Game
{
public:
    /**
     * @brief instance get the static instance of Game class singleton
     * @return the static instance of game
     */
    static Game* instance() {
        if(theInstance == nullptr) {
            theInstance = new Game;
        }
        return theInstance;
    }
    ~Game() {
        delete _dungeonLevel;
        delete _dungeonBuilder;
        delete theInstance;
    }
    Game(Game &other) = delete;
    Game operator=(Game &other) = delete;

    /**
     * \file core::game.h
     * \brief setDungeonType set Games' dungeon level builder to given concrete type
     * @param dungeonLevelBuilder the dungeon level builder to set the Game's dungeon level builder to
     */
    void setDungeonType(core::dungeon::DungeonLevelBuilder* dungeonLevelBuilder);
    /**
     * @brief createExampleLevel creates example dungeon level based on predetermined
     * values, sets _dungeonLevel to the resulting example level
     */
    void createExampleLevel();
    /**
     * @brief createRandomLevel create a randomised dungeon level based on user supplied
     * values for name, width, height and previously set dungeon type
     * @param name of the dungeon level
     * @param width of the dungeon level
     * @param height of the dungeon level
     */
    void createRandomLevel(const std::string &name, const int width, const int height);
    /**
     * @brief displayLevel gets the current dungeon level map representation
     * @return the list of strings representing the dungeon level map
     */
    std::vector<std::string> displayLevel() const;
    /**
     * @brief randomDouble generates and random double between 0.0 and 1.0
     * @return a random double between 0.0 and 1.0 (inclusive)
     */
    double randomDouble(); // non-const, changes private member _randomGenerator

    // FIXME: remove these somehow, not in specification and not what the Game should do
    std::string getDungeonLevelDescription() const;
    int getNumberOfRooms() const;
    std::string getRoomDescription(const int roomNumber) const;


private:
    Game() {}; // hidden constructor for singleton
    static Game* theInstance; // static game instance
    /**
     * @brief _dungeonBuilder the dungeon level builder used to build the dungeon level.
     */
    core::dungeon::DungeonLevelBuilder* _dungeonBuilder;
    /**
     * @brief _dungeonLevel the current dungeon level constructed or under construction
     */
    core::dungeon::DungeonLevel* _dungeonLevel;

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};

    // Example constants
    /**
     * @brief _EXAMPLE_TITLE the title used for the example level when it is generated
     */
    const std::string _EXAMPLE_TITLE= "Example Dungeon Level";
    /**
     * @brief _EXAMPLE_WIDTH the width used for the example level when it is generated
     */
    const int _EXAMPLE_WIDTH= 3;
    /**
     * @brief _EXAMPLE_HEIGHT the height used for the example level when it is generated
     */
    const int _EXAMPLE_HEIGHT = 3;
    // Chance constants
    /**
     * @brief ITEM_CHANCE the chance that an item will appear in each
     * room during random dungeon generation
     */
    const double _ITEM_CHANCE = 0.35;
    /**
     * @brief _CREATURE_CHANCE the chance that a creture will appear in each room
     * during random dungeon generation
     */
    const double _CREATURE_CHANCE = 0.25;
    /**
     * @brief _TRAVERSABLE_CHANCE the chance that an individual door in the dungeon will be traversable
     * during random dungeon generation
     */
    const double _TRAVERSABLE_CHANCE = 0.40;
    /**
     * @brief _LOCKED_CHANCE the chance that an individual door in the dungeon will be locked
     * during random dungeon generation
     */
    const double _LOCKED_CHANCE = 0.30;
    /**
     * @brief _IMPASSABLE_CHANCE the chance that an individual door in the dungeon will be impassable
     * during random dungeon generation
     */
    const double _IMPASSABLE_CHANCE = 0.30;
    // helper methods for random level generation
    /**
     * @brief buildNeighbours builds the neighbouring rooms to an existing room (roomId) if they do not already exist (builtRooms)
     * @param roomId the room to build the neighbours for
     * @param width of the dungeonLevel
     * @param height of the dungeonLevel
     * @param builtRooms the rooms that have already been built
     * @return a list of neighbouring rooms and there associated direction (North, East, S, W) to the current room (roomId)
     */
    std::vector<std::tuple<std::shared_ptr<core::dungeon::Room>, core::dungeon::Room::Direction>> buildNeighbours(const int roomId, int width, int height, std::map<int, std::shared_ptr<core::dungeon::Room>> &builtRooms) const;
    /**
     * @brief buildRandomNeighbouringDoorways randomly determines and builds the doorways between a given room and its neighbours
     * @param room to build the doorways from, i.e. to its neighbours
     * @param width of the dungeonLevel
     * @param height of the dungeonLevel
     * @param neighbours the valid neighbouring rooms to build doorways to and their associated direction (North, East, S, W) from the given room
     */
    void buildRandomNeighbouringDoorways(std::shared_ptr<core::dungeon::Room> room, int width, int height, std::vector<std::tuple<std::shared_ptr<core::dungeon::Room>, core::dungeon::Room::Direction>> &neighbours);  // non-const changes _randomGenerator
    /**
     * @brief getRandomMovementConstraints creates a set of random movement constraints for doorways based on
     * the predetermined chances for traversable, locked, impassable
     * @return the randomised movement constraints
     */
    core::dungeon::DungeonLevelBuilder::MoveConstraints getRandomMovementConstraints(); // non-const: changes _randomGenerator
};

} // namespace core
#endif // GAME_H
