#include <random>
#include <ctime>
#include "game.h"

Game::Game(){}

Game& Game::instance(){
    return theInstance;
}

void setDungeonType(DungeonLevelBuilder dungeonLevelBuilder){}
void Game::createExampleLevel(){}
void Game::createRandomLevel(std::string name, int width, int height){}
void Game::displayLevel(){}
double Game::randomDouble(){
    return _realDistribution(_randomGenerator);
}
