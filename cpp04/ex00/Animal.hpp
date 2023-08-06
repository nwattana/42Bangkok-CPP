#ifndef ANIMAL_CPP
# define ANIMAL_CPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& src);
        virtual ~Animal();

        Animal& operator=(const Animal& rhs);

        std::string getType() const;
        virtual void makeSound() const;
};


#endif