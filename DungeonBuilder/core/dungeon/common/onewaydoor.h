#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include "core/dungeon/doorway.h"

class OneWayDoor: public Doorway
{
public:
    OneWayDoor() : Doorway(){}
    ~OneWayDoor() = default; // TODO: Do I need to declar this as it is already specified in the base class Doorway

    std::string description() override;
    char displayCharacter() override;

};

#endif // ONEWAYDOOR_H
