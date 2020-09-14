#include "doorway.h"

bool Doorway::isPassage(){
    if(isEntrance()) return false;
    if(isExit()) return false;
    // otherwise the doorway is a passage
    return true;
}

void Doorway::connect(std::shared_ptr<Doorway> opposite){}
bool Doorway::isEntrance(){
    return _isEntry;
}
bool Doorway::isExit(){
    return _isExit;
}
