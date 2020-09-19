#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include <memory>
#include "core/dungeon/doorway.h"
#include "core/dungeon/room.h"
namespace core::dungeon::common {
/**
 * @brief The OneWayDoor class a type of Doorway which can only be traversed in one direction
 * A type of traversable RoomEdge
 */
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
