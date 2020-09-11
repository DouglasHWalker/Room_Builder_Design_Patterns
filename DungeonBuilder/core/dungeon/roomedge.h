#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <iostream>

class RoomEdge
{
public:
    RoomEdge();
    virtual std::string description();
    virtual char displayCharacter();
    virtual bool isPassage();

private:
    std::string _description;
    char _displayCharacter;
    bool _isPassage;
};

#endif // ROOMEDGE_H
