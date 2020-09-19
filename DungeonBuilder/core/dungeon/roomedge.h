#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <ostream>
namespace core::dungeon {
/**
 * @brief The RoomEdge class is a single edge (North, South, E, W) of a room.
 * It is the base class for all edge types
 */
class RoomEdge
{
public:
    virtual ~RoomEdge() = default;
    virtual std::string description() const = 0;
    virtual char displayCharacter() const = 0;
    virtual bool isPassage() const = 0;

    friend std::ostream& operator << (std::ostream& os, const RoomEdge& edge);
protected:
    char _displayCharacter;
};

} // namespace core::dungeon
#endif // ROOMEDGE_H
