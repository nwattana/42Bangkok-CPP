#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& src);
        virtual ~Dog();

        Dog& operator=(const Dog& rhs);

        virtual void makeSound() const;
};

#endif