#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& src);
        virtual ~Dog();

        Dog& operator=(const Dog& rhs);
        void makeSound() const;
        void setBrain(int i, std::string idea);
        void getBrain() const;

    private:
        Brain* _brain;
};

#endif