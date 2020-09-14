#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <iostream>
#include <vector>
#include <memory>
#include "room.h"

class DungeonLevel
{
public:
    DungeonLevel(std::string name, int width, int height) : _name{name}, _width{width}, _height{height} {}
    virtual ~DungeonLevel() = default; // WARNING: virtual here might be wrong
    void addRoom(std::shared_ptr<Room> room);
    std::shared_ptr<Room> retrieveRoom(int);
    int width();
    int height();
    std::string name();
    virtual std::string description() = 0;
    std::vector<std::string> display(); // TODO: should I be using vector here

    int numberOfRooms;

protected:
    std::string _description;


private:
    std::string _name;
    int _width;
    int _height;
    std::vector<std::shared_ptr<Room>> _rooms;
};

#endif // DUNGEONLEVEL_H
