#include <iostream>
#include "./Zombie.hpp"

void randomCallchump(std::string name)
{
    std::cout << "this function call randomChump" << std::endl;
    randomChump(name);
    std::cout << "this function call randomChump end" << std::endl;
}

void randomannounce(Zombie& zombie)
{
    std::cout << "randomannounce - - - from outside main ------ -- -- - " << std::endl;
    zombie.announce();
}

int main(void)
{
    Zombie *zombernator = newZombie("Zombernator");
    Zombie *zombieland = newZombie("Zombieland");
    zombieland->announce();
    zombernator->announce();

    randomCallchump("Zombierandom");
    randomChump("Zombiechump");

    randomannounce(*zombernator);

    delete zombernator;
    delete zombieland;
    return (0);
}