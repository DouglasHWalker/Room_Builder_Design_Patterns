#ifndef DOORWAY_H
#define DOORWAY_H
#include "roomedge.h"
namespace core::dungeon {

class Doorway : public RoomEdge
{
public:
    virtual ~Doorway(){
        delete _opposite; // TODO: double check this is correct way to delete bare pointer, virtual?
    }

    virtual std::string description() override = 0;
    virtual char displayCharacter() override = 0;
    bool isPassage() override;

    void connect(Doorway* opposite);
    bool isEntrance();
    bool isExit();
    // WARNING: public getters not in class diagram
    void setEntry(bool isEntry);
    void setExit(bool isExit);

protected:
    bool _isEntry = false;
    bool _isExit = false; // WARNING: revise entry exit
    Doorway* _opposite;
};

} // namespace core::dungeon
#endif // DOORWAY_H
