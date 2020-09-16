#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include "core/dungeon/doorway.h"

class OpenDoorway : public Doorway
{
public:
    OpenDoorway(Room::Direction direction): _direction{direction}{}
    std::string description() override;
    char displayCharacter() override;
private:
    Room::Direction _direction;
};

#endif // OPENDOORWAY_H
