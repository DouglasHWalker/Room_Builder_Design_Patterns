#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include "core/dungeon/doorway.h"
#include "core/dungeon/room.h"
namespace core::dungeon::common {

class OneWayDoor: public Doorway
{
public:
    OneWayDoor(Room::Direction direction): _direction{direction}{}
    std::string description() override;
    char displayCharacter() override;
private:
    Room::Direction _direction;
};

} // namespace core::dungeon::common
#endif // ONEWAYDOOR_H
