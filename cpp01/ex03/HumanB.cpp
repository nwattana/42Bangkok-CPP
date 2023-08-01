#include "HumanB.hpp"

// HumanB::HumanB(std::string name) : _name(name) {
// }

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void)
{
    std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack(void)
{
    if (this->_weapon == NULL)
        std::cout << this->_name << " has no weapon he attack with bear hands" << std::endl;
    else
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}