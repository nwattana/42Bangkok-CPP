#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
    this->_name = name;
}

Zombie::~Zombie( void ) {
    std::cout << this->_name << ": Garrr! ... "<< this->_name << " is dead! X_X~" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}