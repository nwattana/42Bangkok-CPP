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
    std::cout << "FragTrap: Destructor called" << std::endl;
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

std::string FragTrap::getName(void) const {
    return this->_name;
}

int         FragTrap::getHitPoints(void) const {
    return this->_hitPoints;
}

int        FragTrap::getEnergyPoints(void) const {
    return this->_energyPoints;
}

int         FragTrap::getAttackDamage(void) const {
    return this->_attackDamage;
}

bool    FragTrap::isDead(void) {
    if (this->_hitPoints <= 0)
        return true;
    return false;
}

// Member function
void       FragTrap::attack(std::string const & target) {
    if ( this->isDead() ){
        std::cout << "FragTrap " << this->_name << " is dead and can't attack" << std::endl;
        return ;
    }
    ClapTrap::attack(target);
}

void        FragTrap::takeDamage(unsigned int amount) {
    if ( this->isDead() ){
        std::cout << "FragTrap " << this->_name << " is dead and can't take damage" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " take " << amount \
    << " points of damage!" << std::endl;
    ClapTrap::takeDamage(amount);
}

void        FragTrap::beRepaired(unsigned int amount) {
    if ( this->isDead() ){
        std::cout << "FragTrap " << this->_name << " is dead and can't be repaired" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " be repaired " << amount \
    << " points of damage!" << std::endl;
    ClapTrap::beRepaired(amount);
}

void    FragTrap::highFivesGuys() {
    if ( this->isDead() ){
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
