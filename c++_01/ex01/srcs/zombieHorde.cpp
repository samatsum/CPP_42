#include "../include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *heap_array_zombie;
    int     i;

    heap_array_zombie = new Zombie[N];
    while (i < N)
    {
        heap_array_zombie[i] = Zombie(name);
        i++;
    }
    return (heap_array_zombie);
}