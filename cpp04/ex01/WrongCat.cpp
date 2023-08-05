#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Not Meow!" << std::endl;
}

std::string WrongCat::getType() const {
    return this->type;
}