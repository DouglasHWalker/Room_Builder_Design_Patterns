#include "onewaydoor.h"

std::string OneWayDoor::description(){
    // if Entry
    if(_isEntry){
        return "the entrance to the dungeon.";
    }
    // if Exit
    if(_isExit){
        return "the exit to the dungeon (One-way door).";
    }
    return "a One-way Door from another chamber."; // TODO: could implement this to cover the entire description
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
    // otherwise
    switch(_direction){
    case Room::Direction::North:
        return 'v';
    case Room::Direction::South:
        return '^';
    case Room::Direction::East:
        return '<';
    case Room::Direction::West:
        return '>';
    default:
        break;
    }
}
