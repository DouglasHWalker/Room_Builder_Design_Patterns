#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <map>
#include <vector>
#include "room.h"
namespace core::dungeon {

class DungeonLevel
{
public:
    DungeonLevel(const std::string &newName, const int newWidth, const int newHeight)
        : _name{newName}, _width{newWidth}, _height{newHeight} {}
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
