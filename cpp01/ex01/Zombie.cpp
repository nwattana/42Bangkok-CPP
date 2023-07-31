#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " is dead again but he will be back!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << ":"<< this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}