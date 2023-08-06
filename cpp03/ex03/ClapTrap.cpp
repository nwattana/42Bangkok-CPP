#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
    std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap &  ClapTrap::operator=(ClapTrap const & src) {
    std::cout << "ClapTrap " << this->_name << " assignation operator called" << std::endl;
    if (this != &src) {
        this->_name = src._name;
        this->_hitPoints = src._hitPoints;
        this->_energyPoints = src._energyPoints;
        this->_attackDamage = src._attackDamage;
    }
    return *this;
}

std::string ClapTrap::getName(void) const {
    return this->_name;
}

int         ClapTrap::getHitPoints(void) const {
    return this->_hitPoints;
} 

int         ClapTrap::getEnergyPoints(void) const {
    return this->_energyPoints;
}

int         ClapTrap::getAttackDamage(void) const {
    return this->_attackDamage;
}

void        ClapTrap::attack(std::string const & target) {
    if (this->_hitPoints<= 0) {
        std::cout << "ClapTrap " << this->_name << " already dead" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void        ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " already dead" << std::endl;
        return ;
    }
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
}

void        ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " already dead" << std::endl;
        return ;
    }
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " be repaired " << amount << " points of damage!" << std::endl;
}

std::ostream &  operator<<(std::ostream & o, ClapTrap const & i) {
    o << "===== Show ClapTrap Info ==========|" \
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