#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "-------------TEST1(no more hit points)-------------------------" << std::endl;
    ClapTrap player("Cat");

    player.attack("Dog");
    player.takeDamage(2);
    player.takeDamage(5);
    player.takeDamage(6);
    player.beRepaired(1);

    std::cout << "Stats for " << player.getName() << ": " << std::endl;
    std::cout << "Hit points left: " << player.getHitPoints() << std::endl;
    std::cout << "Energy points left: " << player.getEnergyPoints() << std::endl;

    std::cout << "-------------TEST2(no more energy points)-------------------------" << std::endl;
    ClapTrap new_player("Hedgehog");

    new_player.attack("Cat");
    new_player.beRepaired(2);
    new_player.attack("Bear");
    new_player.attack("Platypus");
    new_player.takeDamage(5);
    new_player.attack("Alpaca");
    new_player.attack("Capybara");
    new_player.takeDamage(1);
    new_player.attack("Honey badger");
    new_player.beRepaired(1);
    new_player.attack("Rabbit");
    new_player.beRepaired(3);
    new_player.beRepaired(2);
    std::cout << "Stats for " << new_player.getName() << ": " << std::endl;
    std::cout << "Hit points left: " << new_player.getHitPoints() << std::endl;
    std::cout << "Energy points left: " << new_player.getEnergyPoints() << std::endl;

    std::cout << "-------------TEST3(Anonymous)-------------------------" << std::endl;
    ClapTrap anonymous;
    anonymous.beRepaired(2);
    anonymous.takeDamage(10);
    std::cout << "Stats for " << anonymous.getName() << ": " << std::endl;
    std::cout << "Hit points left: " << anonymous.getHitPoints() << std::endl;
    std::cout << "Energy points left: " << anonymous.getEnergyPoints() << std::endl;
    return 0;
}