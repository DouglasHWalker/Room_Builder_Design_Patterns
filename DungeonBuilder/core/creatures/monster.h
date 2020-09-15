#ifndef MONSTER_H
#define MONSTER_H
#include "abstractcreature.h"

class Monster : public AbstractCreature
{
public:
    Monster(std::string name) : AbstractCreature(name) {
        _displayCharacter = _DISPLAY_CHAR;
    };
    std::unique_ptr<AbstractCreature> clone(){
        return std::make_unique<Monster>(*this);
    }; // TODO: override superclass. Return deep copy of self

private:
    const char _DISPLAY_CHAR = 'M';
};

#endif // MONSTER_H
