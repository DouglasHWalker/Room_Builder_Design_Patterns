#ifndef DOORWAY_H
#define DOORWAY_H
#include "roomedge.h"
namespace core::dungeon {

class Doorway : public RoomEdge
{
public:
    virtual ~Doorway(){
        delete _opposite;
    }
    virtual std::string description() const override = 0;
    virtual char displayCharacter() const  override = 0;
    bool isPassage() const override;

    void connect(Doorway* const opposite);
    bool isEntrance() const;
    bool isExit() const;
    // WARNING: public getters not in class diagram
    void setEntry(const bool isEntry);
    void setExit(const bool isExit);

protected:
    bool _isEntry = false;
    bool _isExit = false; // WARNING: may need to revise entry exit
    Doorway* _opposite;
};

} // namespace core::dungeon
#endif // DOORWAY_H
