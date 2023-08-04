#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    // Test Orthodox Canonical Form
    std::cout << "\n==============Test Orthodox Canonical Form============"\
     << std::endl << std::endl;    
    FragTrap fragcano("fragcano");
    std::cout << fragcano << std::endl;
    FragTrap fragcano2(fragcano);
    std::cout << fragcano2 << std::endl;
    FragTrap fragcano3("fragcano3");
    std::cout << fragcano3 << std::endl;
    fragcano2.takeDamage(50);
    fragcano3 = fragcano2;
    std::cout << fragcano3 << std::endl;
    std::cout << "\n==============End Test Orthodox Canonical Form============"\
     << std::endl << std::endl;



    FragTrap FragTrap("FragTrap");
    std::cout << FragTrap << std::endl;

    FragTrap.beRepaired(50);
    FragTrap.attack("clapTrap");
    FragTrap.takeDamage(50);
    FragTrap.highFivesGuys();
    std::cout<< std::endl << FragTrap << std::endl;

    FragTrap.takeDamage(100);
    std::cout << FragTrap << std::endl;
    
    FragTrap.beRepaired(50);
    FragTrap.attack("clapTrap");
    FragTrap.takeDamage(90);
    FragTrap.highFivesGuys();

    return 0;
}