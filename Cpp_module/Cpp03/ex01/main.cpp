#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "-------------TEST1(no more hit points)-------------------------" << std::endl;
    ScavTrap player("Cat");

    player.attack("Dog");
    player.takeDamage(10);
    player.takeDamage(20);
    player.takeDamage(60);
    player.guardGate();
    player.beRepaired(20);
    player.takeDamage(40);

    std::cout << "Stats for " << player.getName() << ": " << std::endl;
    std::cout << "Hit points left: " << player.getHitPoints() << std::endl;
    std::cout << "Energy points left: " << player.getEnergyPoints() << std::endl;

    std::cout << "-------------TEST2(no more energy points)-------------------------" << std::endl;
    ScavTrap new_player("Pigeon");
    int i = 0;
    while (i < 50)
    {
        std::cout << i << ") ";
        new_player.attack("Worm");
        i++;
    }
    new_player.beRepaired(10);
    new_player.takeDamage(10);
    
    std::cout << "Stats for " << new_player.getName() << ": " << std::endl;
    std::cout << "Hit points left: " << new_player.getHitPoints() << std::endl;
    std::cout << "Energy points left: " << new_player.getEnergyPoints() << std::endl;

    return 0;
}