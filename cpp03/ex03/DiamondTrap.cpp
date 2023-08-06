#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name){
    this->ClapTrap::_name = name + "_clap_name";
    this->_name = name;
    this->_attackDamage = FragTrap::_attackDamage;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_hitPoints = FragTrap::_hitPoints;
    std::cout << "Diamond name:" << this->_name << std::endl;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &  DiamondTrap::operator=(DiamondTrap const & src) {
    if (this != &src) {
        this->_attackDamage = src._attackDamage;
        this->_energyPoints = src._energyPoints;
        this->_hitPoints = src._hitPoints;
        this->_name = src._name;
    }
    return *this;
}

void    DiamondTrap::attack(std::string const & target) {
    ScavTrap::attack(target);
}

void        DiamondTrap::whoAmI() const {
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
    std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getMyName(void) const {
    return this->_name;
}

std::string DiamondTrap::getFragName(void) const {
    return this->FragTrap::getName();
}

std::string DiamondTrap::getScavName(void) const {
    return this->ScavTrap::getName();
}


std::ostream &  operator<<(std::ostream & o, DiamondTrap const & i) {
    o << "===== Show Diamond Info ==========|" << "\n|\tNAME :\t\t" << i.getName() \
    << "\n|\tClapTrap NAME :\t" << i.getMyName() \
    << "\n|\tFragTrap NAME :\t" << i.getFragName() \
    << "\n|\tScavTrap NAME :\t" << i.getScavName();
    std::cout << "\n|\tHP :\t\t";
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