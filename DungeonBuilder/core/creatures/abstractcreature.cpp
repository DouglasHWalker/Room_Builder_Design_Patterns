#include "abstractcreature.h"
namespace core::creatures {

std::string AbstractCreature::name() const {
    return _name;
}
char AbstractCreature::displayCharacter() const {
    return _displayCharacter;
}

void AbstractCreature::setIsBoss() {
    _isBoss = true;
    _name = "Elite " + _name;
}

bool AbstractCreature::isBoss() const {
    return _isBoss;
}

std::ostream &operator <<(std::ostream &os, const AbstractCreature &creature) {
    return os << creature.name();
}

} // namespace core::creatures
