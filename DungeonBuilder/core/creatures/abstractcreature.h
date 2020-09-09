#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <iostream>

class AbstractCreature
{
public:
    AbstractCreature(std::string name);
    AbstractCreature clone();
    std::string name();
    char displayCharacter();
private:
    std::string _name;
    char _displayCharacter;
};

#endif // ABSTRACTCREATURE_H
