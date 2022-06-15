#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <string>

/*fonts color*/
# define FBLACK		"\033[0;30m"
# define FRED		"\033[0;31m"
# define FGREEN		"\033[0;32m"
# define FYELLOW	"\033[0;33m"
# define FBLUE		 "\033[0;34m"
# define FPURPLE	"\033[0;35m"
# define FCYAN		"\x1b[36m"

/*end color*/
# define NONE        "\033[0m"

class ClapTrap
{
protected:
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