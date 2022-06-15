#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "Default ScavTrap constructor called for " << this->name << std::endl;

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "Default ScavTrap constructor called for " << this->name << std::endl;

}

ScavTrap::ScavTrap(ScavTrap const &other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other)
        *this = other;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "Default ScavTrap destructor called for " << this->name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energy_points == 0)
    {
        std::cout << "(ScavTrap) I have no energy points to attack " << target << std::endl;
        return ;
    }
    if (hit_points == 0)
    {
        std::cout << "(ScavTrap) I have no health to attack " << target << std::endl;
        return ;
    }
    energy_points -= 1;
    std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}