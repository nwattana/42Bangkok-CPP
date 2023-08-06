#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat& src);
        ~Cat();

        Cat& operator=(const Cat& rhs);

        void makeSound() const;

    private:
        Brain* _brain;
};

#endif