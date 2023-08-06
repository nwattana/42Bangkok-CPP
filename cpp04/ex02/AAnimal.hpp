#ifndef AANIMAL_CPP
# define AANIMAL_CPP

#include <string>
#include <iostream>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal& src);
        virtual ~AAnimal();

        AAnimal& operator=(const AAnimal& rhs);

        std::string getType() const;
        virtual void makeSound() const = 0;
};


#endif