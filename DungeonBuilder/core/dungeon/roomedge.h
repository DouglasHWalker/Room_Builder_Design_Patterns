#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <iostream>
#include <ostream>
#include <memory>

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
    // TODO: does the RoomEdge need a direction
};

#endif // ROOMEDGE_H
