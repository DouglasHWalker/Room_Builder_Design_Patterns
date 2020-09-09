#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <iostream>

class RoomEdge
{
public:
    RoomEdge();
    std::string description();
    char displayCharacter();
    bool isPassage();

private:
    std::string _description;
    char _displayCharacter;
    bool _isPassage;
};

#endif // ROOMEDGE_H
