#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include "core/dungeon/doorway.h"

class LockedDoor : Doorway
{
public:
    LockedDoor();

    void connect(Doorway opposite);
    bool isEntrance();
    bool isExit();

    std::string description();
    char displayCharacter();
    bool isPassage();
};

#endif // LOCKEDDOOR_H
