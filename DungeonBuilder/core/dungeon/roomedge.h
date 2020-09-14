#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <iostream>
#include <ostream>
#include <memory>

class RoomEdge
{
public:
    virtual std::string description();
    virtual char displayCharacter();
    virtual bool isPassage();

protected:
    std::string _description;
    char _displayCharacter;
    // TODO: does the RoomEdge need a direction
};

#endif // ROOMEDGE_H
