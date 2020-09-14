#ifndef MONSTER_H
#define MONSTER_H
#include "abstractcreature.h"

class Monster : public AbstractCreature
{
public:
    Monster(std::string name) : AbstractCreature(name) {
        _displayCharacter = _DISPLAY_CHAR;
    };
    Monster* clone(){
        return new Monster(*this);
    }; // TODO: override superclass. Return deep copy of self

private:
    const char _DISPLAY_CHAR = 'M';
};

#endif // MONSTER_H
