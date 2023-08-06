#include "ADog.hpp"

ADog::ADog() : AAnimal("ADog")
{
    std::cout << "ADog constructor called" << std::endl;
    this->_brain = new Brain();
}

ADog::ADog(const ADog &src) : AAnimal(src)
{
    std::cout << "ADog copy constructor called" << std::endl;
    this->_brain = new Brain(*src._brain);
}

ADog::~ADog()
{
    delete this->_brain;
    std::cout << "ADog destructor called" << std::endl;
}

void ADog::setBrain(int i, std::string idea)
{
    this->_brain->setIdea(i, idea);
}

void ADog::getBrain() const
{
    int i = 0;
    while (this->_brain->getIdea(i) != "")
    {
        std::cout << this->_brain->getIdea(i) << std::endl;
        i++;
    }
}

ADog &ADog::operator=(const ADog &rhs)
{
    std::cout << "ADog assignation operator called" << std::endl;
    if (this != &rhs)
    {
        AAnimal::operator=(rhs);
        this->_brain = rhs._brain;
    }
    return *this;
}

void ADog::makeSound() const
{
    std::cout << "yap, yap; yip, yip" << std::endl;
}