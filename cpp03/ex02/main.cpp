#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

    {
        ClapTrap clapTrap("clapTrap");
        std::cout << clapTrap << std::endl;
        ClapTrap clapTrapCopy("clapTraCopy");
        std::cout << clapTrapCopy << std::endl;

        clapTrap.attack("clapTrapCopy");
        clapTrapCopy.takeDamage(5);
        std::cout << clapTrapCopy << std::endl;
        clapTrapCopy.beRepaired(5);
        std::cout << clapTrapCopy << std::endl;
        clapTrapCopy.takeDamage(5);
        clapTrapCopy.takeDamage(5);
        std::cout << clapTrapCopy << std::endl;
        clapTrapCopy.takeDamage(5);
    }
    {
        ScavTrap scavTrap("scavTrap");
        std::cout << scavTrap << std::endl;
        scavTrap.beRepaired(50);
        scavTrap.attack("clapTrap");
        scavTrap.takeDamage(50);

        std::cout << "========================== from ScavTrap::guardGate()" << std::endl;
        scavTrap.guardGate();

        
        std::cout << scavTrap << std::endl;
        scavTrap.takeDamage(100);
        std::cout << scavTrap << std::endl;
        scavTrap.beRepaired(50);
        scavTrap.attack("clapTrap");
        scavTrap.takeDamage(90);
        scavTrap.guardGate();
    }
    {
        FragTrap fragTrap("fragTrap");
        std::cout << fragTrap << std::endl;
        fragTrap.beRepaired(50);
        fragTrap.attack("clapTrap");
        fragTrap.takeDamage(50);
        std::cout << "========================== from FragTrap::highFivesGuys()" << std::endl;
        fragTrap.highFivesGuys();
        std::cout << fragTrap << std::endl;
        fragTrap.takeDamage(100);
        std::cout << fragTrap << std::endl;
        fragTrap.beRepaired(50);
        fragTrap.attack("clapTrap");
        fragTrap.takeDamage(90);
        fragTrap.highFivesGuys();
    }

    return 0;
}