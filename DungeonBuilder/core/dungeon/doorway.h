#ifndef DOORWAY_H
#define DOORWAY_H
#include "roomedge.h"

class Doorway : public RoomEdge
{
public:
    Doorway();

    std::string description();
    char displayCharacter();
    bool isPassage();

    void connect(Doorway opposite);
    bool isEntrance();
    bool isExit();

private:
    bool _isEntrance;
    bool _isExit;
};

#endif // DOORWAY_H
