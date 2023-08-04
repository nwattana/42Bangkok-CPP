#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap: Default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

// Copy constructor
ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
    std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

// Assignment operator
ScavTrap &  ScavTrap::operator=(ScavTrap const & src) {
    std::cout << "ScavTrap: Assignment operator called" << std::endl;
    if (this != &src)
    {
        ClapTrap::operator=(src);
        // put code here
    }
    return *this;
}

std::string ScavTrap::getName(void) const {
    return this->_name;
}

int         ScavTrap::getHitPoints(void) const {
    return this->_hitPoints;
}

int        ScavTrap::getEnergyPoints(void) const {
    return this->_energyPoints;
}

int         ScavTrap::getAttackDamage(void) const {
    return this->_attackDamage;
}

bool    ScavTrap::isDead(void) {
    if (this->_hitPoints <= 0)
        return true;
    return false;
}

// Member function
void       ScavTrap::attack(std::string const & target) {
    if ( this->isDead() ){
        std::cout << "ScavTrap " << this->_name << " is dead and can't attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attack " << target \
    << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void        ScavTrap::takeDamage(unsigned int amount) {
    if ( this->isDead() ){
        std::cout << "ScavTrap " << this->_name << " is dead and can't take damage" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " take " << amount \
    << " points of damage!" << std::endl;
    this->_hitPoints -= amount;
}

void        ScavTrap::beRepaired(unsigned int amount) {
    if ( this->isDead() ){
        std::cout << "ScavTrap " << this->_name << " is dead and can't be repaired" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " be repaired " << amount \
    << " points of damage!" << std::endl;
    this->_hitPoints += amount;
}

void    ScavTrap::guardGate() {
    if ( this->isDead() ){
        std::cout << "ScavTrap " << this->_name << " is dead and can't guard gate" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode" << std::endl;
}

// str method
std::ostream &  operator<<(std::ostream & o, ScavTrap const & i) {
    o << "===== Show ScavTrap Info ==========|" \
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
