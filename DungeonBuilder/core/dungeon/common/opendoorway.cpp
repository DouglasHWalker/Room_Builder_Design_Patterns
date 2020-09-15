#include "opendoorway.h"

std::string OpenDoorway::description(){
    return "an Open Doorway to another chamber";
}
char OpenDoorway::displayCharacter(){
    // TODO: depends on direction
    return '>';
}
