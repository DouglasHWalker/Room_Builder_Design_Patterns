#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include "core/dungeon/doorway.h"
namespace core::dungeon::common {

class BlockedDoorway : public Doorway
{
public:
    std::string description() override;
    char displayCharacter() override;
};

} // namespace core::dungeon::common
#endif // BLOCKEDDOORWAY_H
