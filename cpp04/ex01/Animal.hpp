#ifndef ANIMAL_CPP
# define ANIMAL_CPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
    protected:
        std::string _type;
        Brain * brain;

    public:
        Animal(std::string type);
        Animal(const Animal& src);
        virtual ~Animal();

        Animal& operator=(const Animal& rhs);

        std::string getType() const;
        virtual void makeSound() const;
};


#endif