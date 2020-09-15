#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <iostream>
#include <memory>

class AbstractCreature
{
public:
    AbstractCreature(std::string name) : _name{name}{}
    virtual std::unique_ptr<AbstractCreature> clone() = 0;
    std::string name();
    char displayCharacter();

    friend std::ostream& operator<< (std::ostream& os, const AbstractCreature& creature);
protected:
    std::string _name;
    char _displayCharacter = 'M';
    bool isBoss();

};

#endif // ABSTRACTCREATURE_H
