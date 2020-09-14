#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include "core/dungeon/doorway.h"
#include "core/dungeon/room.h"

class LockedDoor : public Doorway
{
public:    
    std::string description() override;
    char displayCharacter() override;
private:
    const char& _DISPLAY_CHAR = 'X';
};

#endif // LOCKEDDOOR_H
