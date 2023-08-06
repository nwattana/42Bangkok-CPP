#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat type constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src){
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
    this->_brain = new Brain(*src._brain);
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs._type;
        this->_brain = rhs._brain;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

