#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "-------------TEST1-------------------------" << std::endl;
    ScavTrap player("Cat");
    FragTrap new_player("Dog");

    player.attack("Dog");
    new_player.takeDamage(20);
    new_player.attack("Cat");
    player.takeDamage(30);
    new_player.highFivesGuys();
    new_player.takeDamage(90);

    std::cout << "Stats for " << player.getName() << ": " << std::endl;
    std::cout << "Hit points left: " << player.getHitPoints() << std::endl;
    std::cout << "Energy points left: " << player.getEnergyPoints() << std::endl;

    std::cout << "Stats for " << new_player.getName() << ": " << std::endl;
    std::cout << "Hit points left: " << new_player.getHitPoints() << std::endl;
    std::cout << "Energy points left: " << new_player.getEnergyPoints() << std::endl;

    return 0;
}