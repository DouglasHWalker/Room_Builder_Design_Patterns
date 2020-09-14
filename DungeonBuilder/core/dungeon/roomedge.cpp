#include "roomedge.h"

std::ostream & operator << (std::ostream& os, const RoomEdge& edge){
    os << edge._description;
    return os;
}
