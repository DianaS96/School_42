#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "Default FragTrap constructor called for " << this->name << std::endl;

}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "Default FragTrap constructor called for " << this->name << std::endl;

}

FragTrap::FragTrap(FragTrap const &other) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other)
        *this = other;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "Default FragTrap destructor called for " << this->name << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " is giving high five" << std::endl;
}