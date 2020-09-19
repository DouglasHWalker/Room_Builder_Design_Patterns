#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <map>
#include <vector>
#include "room.h"
namespace core::dungeon {
/**
 * @brief The DungeonLevel class representing the dungeon level and all of its rooms and its components.
 */
class DungeonLevel
{
public:
    DungeonLevel(const std::string &newName, const int newWidth, const int newHeight)
        : _name{newName}, _width{newWidth}, _height{newHeight} {}
    virtual ~DungeonLevel() = default;
    void addRoom(const std::shared_ptr<Room> room);
    std::shared_ptr<Room> retrieveRoom(const int id) const;
    int width() const;
    int height() const;
    std::string name() const;
    /**
     * @brief description get a description of the dungeon level: name width and height
     * @return a description of the dungeon level (name, width and height)
     */
    virtual std::string description() const = 0;
    /**
     * @brief display get a list of string representing the dungeon level map, including all of its rooms
     * @return a list of strings representing a map of the dungeon level and its rooms
     */
    std::vector<std::string> display() const;

protected:
    /**
     * @brief _name of the dungeon level
     */
    std::string _name;
    /**
     * @brief _width of the dungeon level
     */
    int _width;
    /**
     * @brief _height of the dungeon level
     */
    int _height;
    /**
     * @brief _rooms a map (unique room ids only) of rooms in the dungeon level
     */
    std::map<int, std::shared_ptr<Room>> _rooms;
};

} // namespace core::dungeon
#endif // DUNGEONLEVEL_H
