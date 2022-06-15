#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &other);
	ClapTrap &operator=(ClapTrap const &other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	unsigned int getHitPoints(void);
	unsigned int getEnergyPoints(void);
	unsigned int getAttackDamage(void);
	std::string getName(void);
	
};

#endif