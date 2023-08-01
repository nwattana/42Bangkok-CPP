#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main (void)
{
        Weapon club = Weapon("crude spiked club");
    
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        Weapon club2 = Weapon("Samurai sword");

        HumanB jim("Jim karry");
        jim.attack(); // SIGSEGV because weapon is not set
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();

    return (0);
}