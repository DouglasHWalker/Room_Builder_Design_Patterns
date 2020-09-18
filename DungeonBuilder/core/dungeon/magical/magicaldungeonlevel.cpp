#include <sstream>
#include "magicaldungeonlevel.h"
namespace core::dungeon::magical {

std::string MagicalDungeonLevel::description() const {
    std::stringstream ss;
    ss << _name << "\nSize: " << _width << " x " << _height << "\nType: Dragons Den (Magical Dungeon)";
    return ss.str();
}

} // namespace core::dungeon::magical
