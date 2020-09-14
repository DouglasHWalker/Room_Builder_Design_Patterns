#ifndef DOORWAY_H
#define DOORWAY_H
#include "room.h"

class Doorway : public RoomEdge
{
public:
    virtual ~Doorway(){
        delete _opposite; // TODO: double check this is correct way to delete bare pointer, virtual?
    }

    virtual std::string description() override; // TODO: should this be virtual again, override?
    virtual char displayCharacter() override; // TODO: should this be virtual again, override?
    bool isPassage() override; // TODO: override?

    void connect(std::shared_ptr<Doorway> opposite);
    bool isEntrance();
    bool isExit();

protected:
    bool _isEntry = false;
    bool _isExit = false; // WARNING: revise entry exit
    Doorway* _opposite;

};

#endif // DOORWAY_H
