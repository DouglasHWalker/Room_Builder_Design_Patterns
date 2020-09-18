#include "item.h"
namespace core::items {

std::string Item::name() const{
    return _name;
}

char Item::displayCharacter() const{
    return _displayCharacter;
}

std::ostream & operator << (std::ostream & os, const Item & item) {
    return os << item._name;
}

} // namespace core::items
