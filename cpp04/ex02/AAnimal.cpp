#include "AAnimal.hpp"


AAnimal::AAnimal(std::string type) : _type(type) {
    std::cout << "Animal type constructor called" << std::endl;
    this->brain = new Brain();
}

AAnimal::AAnimal(const AAnimal& src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

AAnimal::~AAnimal() {
    delete this->brain;
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

std::string AAnimal::getType() const {
    return this->_type;
}
