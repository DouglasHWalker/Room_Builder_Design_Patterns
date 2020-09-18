#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <ostream>
#include <memory>
namespace core::creatures {

class AbstractCreature
{
public:
    AbstractCreature(std::string name) : _name{name}{}
    virtual std::unique_ptr<AbstractCreature> clone() const = 0;
    std::string name() const;
    char displayCharacter() const;
    bool isBoss() const;
    void setIsBoss();

    friend std::ostream& operator<< (std::ostream& os, const AbstractCreature& creature);

protected:
    char _displayCharacter;
private:
    std::string _name;
    bool _isBoss = false;
};

} // namespace core::cretures
#endif // ABSTRACTCREATURE_H
