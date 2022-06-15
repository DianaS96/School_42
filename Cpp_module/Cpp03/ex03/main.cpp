#include "DiamondTrap.hpp"
int main(void)
{
    std::cout << "-------------TEST1-------------------------" << std::endl;
    DiamondTrap player("Diamond");

    std::cout << FYELLOW << "------------------Stats------------------" << NONE << std::endl;
    std::cout << "Stats for " << player.getName() << ": " << std::endl;
    std::cout << "Hit points : " << player.getHitPoints() << std::endl;
    std::cout << "Energy points : " << player.getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << player.getAttackDamage() << std::endl;

    std::cout << FBLUE << "------------------Attack function------------------" << NONE << std::endl;
    player.attack("Human");
    std::cout << FGREEN << "------------------whoAmI function------------------" << NONE << std::endl;
    player.whoAmI();
    std::cout << FPURPLE << "------------------guardGate function------------------" << NONE << std::endl;
    player.guardGate();
    std::cout << FCYAN << "------------------highFivesGuys function------------------" << NONE << std::endl;
    player.highFivesGuys();

    return 0;
}