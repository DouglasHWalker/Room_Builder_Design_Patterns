#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include <memory>
#include "core/dungeon/doorway.h"
#include "core/dungeon/room.h"
namespace core::dungeon::common {

class OneWayDoor: public Doorway
{
public:
    OneWayDoor(const Room::Direction &newDirection): _direction{newDirection}{}
    std::string description() const override;
    char displayCharacter() const override;
private:
    Room::Direction _direction;
};

} // namespace core::dungeon::common
#endif // ONEWAYDOOR_H
