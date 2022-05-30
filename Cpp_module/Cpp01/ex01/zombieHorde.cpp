#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *zombies = new Zombie[N];
    int     i;

    i = 0;
    while (i < N)
    {
        zombies[i].setName(name);
        i++;
    }
    return (zombies);
}