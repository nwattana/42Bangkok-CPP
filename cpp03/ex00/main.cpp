#include "ClapTrap.hpp"

int main(void) {

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



    return 0;
}