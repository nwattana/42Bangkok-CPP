#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& src) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
    int i = 0;
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &rhs)
    {
        for (i = 0; i < 100; i++)
            this->_ideas[i] = rhs._ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int i) const {
    return this->_ideas[i];
}

void Brain::setIdea(int i, std::string idea) {
    this->_ideas[i] = idea;
}
