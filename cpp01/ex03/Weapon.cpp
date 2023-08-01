#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon " << this->_type << " destroyed" << std::endl;
    return;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

std::string Weapon::getType(void)
{
    return (this->_type);
}