#ifndef CHARACHTER_HPP 
#define CHARACHTER_HPP 

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];
public:
    Character();
    Character(const std::string &name);
	Character(const Character &character);
    Character	&operator=(const Character &character);
    ~Character();
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif