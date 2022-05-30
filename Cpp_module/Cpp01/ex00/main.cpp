#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("Dog");

    randomChump("Cat");
    zombie->announce();

    delete zombie;
    return (0);
}