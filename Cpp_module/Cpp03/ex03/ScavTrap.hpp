#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(std::string name, unsigned int amount_hit_points, unsigned int amount_attack_damage);
	ScavTrap(ScavTrap const &other);
	ScavTrap &operator=(ScavTrap const &other);
    ~ScavTrap();

    void guardGate();
	void attack(const std::string& target);
};

#endif