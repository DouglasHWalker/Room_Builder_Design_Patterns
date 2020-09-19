#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <ostream>
#include <memory>
namespace core::creatures {
/**
 * @brief The AbstractCreature class is the base class for all creatures in the game
 */
class AbstractCreature
{
public:
    AbstractCreature(std::string newName) : _name{newName}{}
    virtual ~AbstractCreature() = default;
    virtual std::unique_ptr<AbstractCreature> clone() const = 0;
    std::string name() const;
    char displayCharacter() const;
    bool isBoss() const;
    void setIsBoss();

    friend std::ostream &operator <<(std::ostream &os, const AbstractCreature &creature);

protected:
    char _displayCharacter;
private:
    /**
     * @brief _name the name of the creature
     */
    std::string _name;
    /**
     * @brief _isBoss is this creature a boss creature
     */
    bool _isBoss = false;
};

} // namespace core::cretures
#endif // ABSTRACTCREATURE_H
