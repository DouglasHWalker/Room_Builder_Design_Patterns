#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <map>
#include <vector>
#include "room.h"
namespace core::dungeon {

class DungeonLevel
{
public:
    DungeonLevel(std::string name, int width, int height) : _name{name}, _width{width}, _height{height} {}
    virtual ~DungeonLevel() = default; // WARNING: virtual here might be wrong
    void addRoom(const std::shared_ptr<Room> room);
    std::shared_ptr<Room> retrieveRoom(const int id) const;
    int width() const;
    int height() const;
    std::string name() const;
    virtual std::string description() const = 0;
    std::vector<std::string> display() const;

protected:
    std::string _name;
    int _width;
    int _height;
    std::map<int, std::shared_ptr<Room>> _rooms;
};

} // namespace core::dungeon
#endif // DUNGEONLEVEL_H
