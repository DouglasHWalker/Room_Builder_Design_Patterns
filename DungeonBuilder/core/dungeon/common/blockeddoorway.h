#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include "core/dungeon/doorway.h"
namespace core::dungeon::common {
/**
 * @brief The BlockedDoorway class a type of Doorway which cannot be traversed
 * A type of non-traversable RoomEdge
 */
class BlockedDoorway : public Doorway
{
public:
    std::string description() const override;
    char displayCharacter() const override;
};

} // namespace core::dungeon::common
#endif // BLOCKEDDOORWAY_H
