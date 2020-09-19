#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include "core/dungeon/doorway.h"
#include "core/dungeon/room.h"
namespace core::dungeon::common {
/**
 * @brief The OpenDoorway class a type of Doorway which can be traversed in both directions
 * A type of traversable RoomEdge
 */
class OpenDoorway : public Doorway
{
public:
    OpenDoorway(const Room::Direction &newDirection): _direction{newDirection}{}
    std::string description() const override;
    char displayCharacter() const override;
private:
    Room::Direction _direction;
};

} // namespace core::dungeon::common
#endif // OPENDOORWAY_H
