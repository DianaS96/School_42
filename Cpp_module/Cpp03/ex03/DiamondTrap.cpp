#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Anonymous"), FragTrap(), ScavTrap(), name("Anonymous")
{
    ClapTrap::name = name + "_clap_name";
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
    std::cout << "Default DiamondTrap constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name, FragTrap::hit_points, FragTrap::attack_damage), name(name) {
    std::cout << "Default DiamondTrap constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) {
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &other)
        *this = other;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Default DiamondTrap destructor called for " << this->name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}