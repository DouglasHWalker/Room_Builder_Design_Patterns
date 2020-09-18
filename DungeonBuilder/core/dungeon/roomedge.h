#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <ostream>
namespace core::dungeon {

class RoomEdge
{
public:
    virtual std::string description() = 0;
    virtual char displayCharacter() = 0;
    virtual bool isPassage() = 0;
    friend std::ostream& operator <<(std::ostream& os, const RoomEdge& edge);
protected:
    std::string _description;
    char _displayCharacter;
};

} // namespace core::dungeon
#endif // ROOMEDGE_H
