#include "lockeddoor.h"

std::string LockedDoor::description(){
    return "a Locked Door to another chamber."; // TODO: could implement this to cover the entire description
}
char LockedDoor::displayCharacter(){
    return '@';
}
