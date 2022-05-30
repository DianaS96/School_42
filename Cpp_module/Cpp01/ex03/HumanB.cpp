#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name) {
}

HumanB::~HumanB() {}

void HumanB::attack() {
    if (weapon != NULL)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " can't attack" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}