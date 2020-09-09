#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include "core/dungeon/doorway.h"

class OpenDoorway : Doorway
{
public:
    OpenDoorway();

    void connect(Doorway opposite);
    bool isEntrance();
    bool isExit();

    std::string description();
    char displayCharacter();
    bool isPassage();
};

#endif // OPENDOORWAY_H
