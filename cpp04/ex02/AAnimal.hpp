#ifndef AANIMAL_CPP
# define AANIMAL_CPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal {
    protected:
        std::string _type;
        Brain * brain;

    public:
        AAnimal(std::string type);
        AAnimal(const AAnimal& src);
        virtual ~AAnimal() = 0;

        AAnimal& operator=(const AAnimal& rhs);

        std::string getType() const;
        virtual void makeSound() const = 0;
};


#endif