#include "HumanA.hpp"

// https://stackoverflow.com/questions/19576458/constructor-for-must-explicitly-initialize-the-reference-member
HumanA::HumanA(std::string _name, Weapon &_Weapon) : weapon(_Weapon) {
    this->name = _name;
} 

HumanA::~HumanA() {}

void HumanA::attack() {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}