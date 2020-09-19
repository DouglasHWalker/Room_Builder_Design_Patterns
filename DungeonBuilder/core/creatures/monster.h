#ifndef MONSTER_H
#define MONSTER_H


#include "abstractcreature.h"
namespace core::creatures {
/**
 * @brief The Monster class is a type of AbstractCreature (@sa core::creatures::AbstractCreature)
 */
class Monster : public AbstractCreature
{
public:
    Monster(const std::string &name) : AbstractCreature(name) {
        _displayCharacter = _DISPLAY_CHAR;
    };
    std::unique_ptr<AbstractCreature> clone() const override{
        return std::make_unique<Monster>(*this);
    };

private:
    const char _DISPLAY_CHAR = 'M';
};

} // namespace core::creatures
#endif // MONSTER_H
