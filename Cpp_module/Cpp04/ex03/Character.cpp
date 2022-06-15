#include "Character.hpp"

Character::Character() : name("None") {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const std::string &name) : name(name) {
    std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}


Character::Character(Character const & character) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    this->name = character.getName();
}

Character &Character::operator=(const Character &character) {
    if (this != &character)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            if (character.inventory[i])
                inventory[i] = character.inventory[i];
            else
                inventory[i] = NULL;
        }
        name = character.getName();
    }
    return (*this);
}

Character::~Character() {
std::cout << "Character default destructor called" << std::endl;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return ;
        }
    }
    std::cout << "No space for new materia" << std::endl;
}

void Character::unequip(int idx) {
    if (idx > 0 && idx < 4 && inventory[idx])
    {
        inventory[idx] = NULL;
        return ;
    }
    std::cout << "There is nothing to unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        inventory[idx]->use(target);
        return ;
    }
    std::cout << "There is nothing to use" << std::endl;
}

std::string const & Character::getName() const {
    return name;
}