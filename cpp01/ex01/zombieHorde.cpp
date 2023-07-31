#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];
    int i=0;
    if (N <= 0 || name.empty())
    {
        std::cout << "ERROR: ZOMBIE WANT TO EAT YOUR BRAIN BUT HE CAN'T FIND YOURS!" << std::endl;
        return (NULL);
    }

    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return (horde);
}