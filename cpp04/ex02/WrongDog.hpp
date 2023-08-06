#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongDog : protected WrongAnimal
{
    public:
        WrongDog();
        WrongDog(const WrongDog &copy);
        ~WrongDog();
        WrongDog&	operator=(const WrongDog &other);

        std::string	getType() const;
        void	makeSound() const;
};

#endif