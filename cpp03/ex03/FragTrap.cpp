#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap:" <<this->_name << " constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

// Copy constructor
FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
    std::cout << "FragTrap: Copy constructor called" << std::endl;
}

// Destructor
FragTrap::~FragTrap(void) {
    std::cout << "FragTrap: Destructor called from Frag trap\"Good Bye\"" << std::endl;
}

// Assignment operator
FragTrap &  FragTrap::operator=(FragTrap const & src) {
    std::cout << "FragTrap: Assignment operator called" << std::endl;
    if (this != &src)
    {
        ClapTrap::operator=(src);
        // put code here
    }
    return *this;
}

// Member function
void    FragTrap::highFivesGuys() {
    if ( this->_hitPoints <= 0 ){
        std::cout << "FragTrap " << this->_name << " is dead and can't guard gate" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " Yay! Here's a big virtual high five for you! " << std::endl;
}

std::ostream &  operator<<(std::ostream & o, FragTrap const & i) {
    o << "===== Show FragTrap Info ==========|" \
    << "\n|\tNAME :\t\t" << i.getName() \
    << "\n|\tHP :\t\t";
    if (i.getHitPoints() > 0){
        o << i.getHitPoints();
    }
    else{
        o << "DEAD";
    }
    o << "\n|\tEnergy :\t" << i.getEnergyPoints() \
    << "\n|\tActtck :\t" << i.getAttackDamage() \
    << "\n===================================|\n";

    return o;
}
