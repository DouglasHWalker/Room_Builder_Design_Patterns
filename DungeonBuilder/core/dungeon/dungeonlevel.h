#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <iostream>
#include <vector>
#include "room.h"

class DungeonLevel
{
public:
    DungeonLevel(std::string name, int width, int height);

    void addRoom(Room room);
    Room retrieveRoom(int);
    int width();
    int height();
    std::string name();
    std::string description();
    std::vector<std::string> display(); // TODO: could use vector instead

    int numberOfRooms;

};

#endif // DUNGEONLEVEL_H
