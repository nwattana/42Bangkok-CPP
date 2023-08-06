#include "Animal.hpp"


Animal::Animal(std::string type) : _type(type) {
    std::cout << "Animal type constructor called" << std::endl;
    this->brain = new Brain();
}

Animal::Animal(const Animal& src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal() {
    delete this->brain;
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

std::string Animal::getType() const {
    return this->_type;
}


void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}
