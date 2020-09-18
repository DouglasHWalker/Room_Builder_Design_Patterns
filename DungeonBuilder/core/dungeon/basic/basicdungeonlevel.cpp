#include <sstream>
#include "basicdungeonlevel.h"
namespace core::dungeon::basic {

std::string BasicDungeonLevel::description() const {
    std::stringstream ss;
    ss << _name << "\nSize: " << _width << " x " << _height << "\nType: Dark Cave (Basic Dungeon)";
    return ss.str();
}

} // namespace core::dungeon::basic
