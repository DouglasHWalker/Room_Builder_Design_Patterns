#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <iostream>
#include <vector>
#include "room.h"

class DungeonLevel
{
public:
    DungeonLevel(std::string name, int width, int height);

    void addRoom(Room *room);
    Room retrieveRoom(int);
    int width();
    int height();
    std::string name();
    virtual std::string description();
    std::vector<std::string> display(); // TODO: should I be using vector here

    int numberOfRooms;

private:
    std::string _name;
    int _width;
    int _height;
    std::string _description;
    std::vector<Room> _rooms;
};

#endif // DUNGEONLEVEL_H
