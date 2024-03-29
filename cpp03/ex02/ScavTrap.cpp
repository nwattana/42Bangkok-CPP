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

// Member function Polymorphed
void       ScavTrap::attack(std::string const & target) {
    if ( this->_hitPoints <= 0 ){
        std::cout << "ScavTrap " << this->_name << " is dead and can't attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attack " << target \
    << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}


void    ScavTrap::guardGate() {
    if ( this->_hitPoints <= 0 ){
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
