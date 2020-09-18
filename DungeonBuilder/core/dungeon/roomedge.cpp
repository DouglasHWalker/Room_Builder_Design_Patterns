#include "roomedge.h"
namespace core::dungeon {

std::ostream & operator << (std::ostream& os, const RoomEdge& edge){
    os << edge._description;
    return os;
}

} // namespace core::dungeon
