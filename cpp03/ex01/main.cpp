#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

    ClapTrap clapTrap("clapTrap");
    std::cout << clapTrap << std::endl;

    ScavTrap scavTrap("scavTrap");
    std::cout << scavTrap << std::endl;

    scavTrap.beRepaired(50);
    scavTrap.attack("clapTrap");
    scavTrap.takeDamage(50);
    scavTrap.guardGate();
    std::cout << scavTrap << std::endl;

    scavTrap.takeDamage(100);
    std::cout << scavTrap << std::endl;
    
    scavTrap.beRepaired(50);
    scavTrap.attack("clapTrap");
    scavTrap.takeDamage(90);
    scavTrap.guardGate();

    return 0;
}