#include "abstractcreature.h"

std::string AbstractCreature::name(){
    return _name;
}
char AbstractCreature::displayCharacter(){
    return _displayCharacter;
}

void AbstractCreature::setIsBoss(){
    _isBoss = true;
    _name = "Elite " + _name;
}

bool AbstractCreature::isBoss(){
    return _isBoss;
}

std::ostream & operator << (std::ostream& os, const AbstractCreature& creature){
    return os << creature._name;
}
