#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include "core/dungeon/doorway.h"

class OneWayDoor: public Doorway
{
public:
    OneWayDoor(Room::Direction direction): _direction{direction}{}
    std::string description() override;
    char displayCharacter() override;
private:
    Room::Direction _direction;
};

#endif // ONEWAYDOOR_H
