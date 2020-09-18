#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include "core/dungeon/doorway.h"
#include "core/dungeon/room.h"
namespace core::dungeon::common {

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
