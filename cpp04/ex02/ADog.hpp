#ifndef ADOG_HPP
# define ADOG_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class ADog : public AAnimal {
    public:
        ADog();
        ADog(const ADog& src);
        virtual ~ADog();

        ADog& operator=(const ADog& rhs);
        void makeSound() const;
        void setBrain(int i, std::string idea);
        void getBrain() const;

    private:
        Brain* _brain;
};

#endif