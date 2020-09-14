#ifndef MONSTER_H
#define MONSTER_H
#include "abstractcreature.h"

class Monster : public AbstractCreature
{
public:
    Monster(std::string name) : AbstractCreature(name) {};
    Monster* clone(){
        return new Monster(*this);
    }; // TODO: override superclass. Return deep copy of self
};

#endif // MONSTER_H
