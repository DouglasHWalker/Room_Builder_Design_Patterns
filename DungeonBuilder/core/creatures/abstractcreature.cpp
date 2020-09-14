#include "abstractcreature.h"

std::string AbstractCreature::name(){
    return _name;
}
char AbstractCreature::displayCharacter(){
    return _displayCharacter;
}

void AbstractCreature::setToBoss(){
    _name = "Elite " + _name;
    _displayCharacter += '*';
}

std::ostream & operator << (std::ostream& os, const AbstractCreature& creature){
    return os << creature._name;
}
