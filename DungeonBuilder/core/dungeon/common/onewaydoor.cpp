#include "onewaydoor.h"

std::string OneWayDoor::description(){
    // if Entry
    if(_isEntry){
        return " is the entrance to the dungeon.";
    }
    // if Exit
    if(_isExit){
        return " is the exit to the dungeon (One-way door).";
    }
    return "One-way Door"; // TODO: could implement this to cover the entire description
}
char OneWayDoor::displayCharacter(){
    // if Entry
    if(_isEntry){
        return 'I';
    }
    // if Exit
    if(_isExit){
        return 'O';
    }
    // TODO: depends on direction
    return '^';
}
