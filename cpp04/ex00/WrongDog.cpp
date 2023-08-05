#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog") {
    std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& src) : WrongAnimal(src) {
    std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& rhs) {
    std::cout << "WrongDog assignation operator called" << std::endl;
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    return *this;
}

void WrongDog::makeSound() const {
    std::cout << "Oh yeah Baby!" << std::endl;
}

std::string WrongDog::getType() const {
    return this->type;
}