#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <iostream>

class AbstractCreature
{
public:
    AbstractCreature(std::string name) : _name{name}{}
    virtual AbstractCreature *clone() = 0;
    std::string name();
    char displayCharacter();
protected:
    std::string _name;
    char _displayCharacter;
};

#endif // ABSTRACTCREATURE_H
