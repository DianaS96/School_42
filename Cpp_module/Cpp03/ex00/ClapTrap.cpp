#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "Default constructor called for " << this->name << std::endl;
}

ClapTrap::ClapTrap() : name("Anonymous"), hit_points(10), energy_points(10), attack_damage(0) {
        std::cout << "Default constructor called for " << this->name << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Default destructor called for " << this->name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        *this = other;
    return (*this);
}

unsigned int ClapTrap::getHitPoints() {
    return (this->hit_points);
}

unsigned int ClapTrap::getEnergyPoints() {
    return (this->energy_points);
}

unsigned int ClapTrap::getAttackDamage() {
    return (this->attack_damage);
}

std::string ClapTrap::getName() {
    return (this->name);
}

void ClapTrap::attack(const std::string& target) {
    if (energy_points == 0)
    {
        std::cout << "I have no energy points to attack " << target << std::endl;
        return ;
    }
    if (hit_points == 0)
    {
        std::cout << "I have no health to attack " << target << std::endl;
        return ;
    }
    energy_points -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energy_points == 0)
    {
        std::cout << "I have no energy points to be repaired" << std::endl;
        return ;
    }
    if (hit_points == 0)
    {
        std::cout << "I have no health to be repaired" << std::endl;
        return ;
    }
    hit_points += amount;
    energy_points -= 1;
    std::cout << "ClapTrap " << name << " repairs itself and gets " << amount << " hitpoints back" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hit_points == 0)
    {
        std::cout << "ClapTrap " << name << " is dead, he can not be attacked anymore!" << std::endl;
        return;
    }
    if (hit_points <= amount)
    {
        std::cout << "ClapTrap " << name << " was attacked and lose " << hit_points << " hitpoints" << std::endl;
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        hit_points = 0;
        return ;
    }
    std::cout << "ClapTrap " << name << " was attacked and lose " << amount << " hitpoints" << std::endl;
    hit_points -= amount;
}