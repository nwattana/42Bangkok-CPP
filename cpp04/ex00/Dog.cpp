#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &rhs)
        Animal::operator=(rhs);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}