#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include "core/dungeon/doorway.h"

class BlockedDoorway : Doorway
{
public:
    BlockedDoorway();

    void connect(Doorway opposite);
    bool isEntrance();
    bool isExit();

    std::string description();
    char displayCharacter();
    bool isPassage();

};

#endif // BLOCKEDDOORWAY_H
