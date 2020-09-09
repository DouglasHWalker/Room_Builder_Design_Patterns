#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include "core/dungeon/doorway.h"

class OneWayDoor
{
public:
    OneWayDoor();

    void connect(Doorway opposite);
    bool isEntrance();
    bool isExit();

    std::string description();
    char displayCharacter();
    bool isPassage();
};

#endif // ONEWAYDOOR_H
