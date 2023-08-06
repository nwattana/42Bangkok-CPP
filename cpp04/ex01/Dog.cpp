#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*src._brain);
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::setBrain(int i, std::string idea)
{
    this->_brain->setIdea(i, idea);
}

void Dog::getBrain() const
{
    int i = 0;
    while (this->_brain->getIdea(i) != "")
    {
        std::cout << this->_brain->getIdea(i) << std::endl;
        i++;
    }
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        this->_brain = rhs._brain;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "yap, yap; yip, yip" << std::endl;
}