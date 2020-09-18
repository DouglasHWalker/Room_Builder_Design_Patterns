#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include "core/dungeon/doorway.h"
namespace core::dungeon::common {

class BlockedDoorway : public Doorway
{
public:
    std::string description() const override;
    char displayCharacter() const override;
};

} // namespace core::dungeon::common
#endif // BLOCKEDDOORWAY_H
