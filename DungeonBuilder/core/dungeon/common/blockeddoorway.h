#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include "core/dungeon/doorway.h"
#include "core/dungeon/room.h"

class BlockedDoorway : public Doorway
{
public:
    std::string description() override;
    char displayCharacter() override;
private:
    const char& _DISPLAY_CHAR = 'X';
};

#endif // BLOCKEDDOORWAY_H
