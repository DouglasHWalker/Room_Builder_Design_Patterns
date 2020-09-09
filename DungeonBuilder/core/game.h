#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game
{
public:
    static Game instance();
    Game(Game &other) = delete;
    Game operator=(Game &other) = delete; // TODO: double check this is the right way to do

//    setDungeonType(DungeonLevelBuilder);
    void createExampleLevel();
    void createRandomLevel(std::string name, int width, int height);
    void displayLevel();
    double randomDouble();
private:
    Game();
    static Game theInstance;
};

#endif // GAME_H
