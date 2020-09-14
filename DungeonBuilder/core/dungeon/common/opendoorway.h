#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include "core/dungeon/doorway.h"

class OpenDoorway : public Doorway
{
public:
    std::string description() override;
    char displayCharacter() override;


};

#endif // OPENDOORWAY_H
