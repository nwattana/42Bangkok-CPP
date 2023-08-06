#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat type constructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src){
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

