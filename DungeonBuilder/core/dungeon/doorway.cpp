#include "doorway.h"

bool Doorway::isPassage(){
    if(isEntrance() || isExit()) return false;
    // otherwise the doorway is a passage
    return true;
}

void Doorway::connect(Doorway* opposite){
    _opposite = opposite;
}

bool Doorway::isEntrance(){
    return _isEntry;
}

bool Doorway::isExit(){
    return _isExit;
}

void Doorway::setEntry(bool isEntry){
    _isEntry = isEntry;
}

void Doorway::setExit(bool isExit){
    _isExit = isExit;
}
