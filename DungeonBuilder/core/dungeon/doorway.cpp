#include "doorway.h"
namespace core::dungeon {

bool Doorway::isPassage() const{
    if(isEntrance() || isExit()) return false;
    // otherwise the doorway is a passage
    return true;
}

void Doorway::connect(Doorway* const opposite){
    _opposite = opposite;
}

bool Doorway::isEntrance() const{
    return _isEntry;
}

bool Doorway::isExit() const{
    return _isExit;
}

void Doorway::setEntry(const bool isEntry){
    _isEntry = isEntry;
}

void Doorway::setExit(const bool isExit){
    _isExit = isExit;
}

} // namespace core::dungeon
