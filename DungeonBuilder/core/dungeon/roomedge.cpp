#include "roomedge.h"

namespace core::dungeon {

std::ostream& operator << (std::ostream& os, const RoomEdge& edge){
    return os << edge.description();
}

} // namespace core::dungeon
