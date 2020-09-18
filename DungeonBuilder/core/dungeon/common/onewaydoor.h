#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include <memory>
#include "core/dungeon/doorway.h"
#include "core/dungeon/room.h"
namespace core::dungeon::common {

class OneWayDoor: public Doorway
{
public:
    OneWayDoor(Room::Direction direction): _direction{direction}{}
    std::string description() const override;
    char displayCharacter() const override;
private:
    Room::Direction _direction;
};

} // namespace core::dungeon::common
#endif // ONEWAYDOOR_H
