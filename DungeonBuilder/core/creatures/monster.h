#ifndef MONSTER_H
#define MONSTER_H
#include "abstractcreature.h"

class Monster : AbstractCreature
{
public:
    Monster();

    Monster clone(); // TODO: override superclass. Return deep copy of self
};

#endif // MONSTER_H
