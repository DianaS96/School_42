#include "Zombie.hpp"

int main(void)
{
    int     N = 4;
    int     i = 0;
    Zombie *zombies = zombieHorde(N, "Zombie");

    while (i < N)
        zombies[i++].announce();
    delete [] zombies;
    return (0);
}