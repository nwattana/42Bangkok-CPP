#include <iostream>
#include "AAnimal.hpp"
#include "ADog.hpp"

int main(void)
{
    //     const AAnimal *meta = new AAnimal();
    //     meta->makeSound();
    //     delete meta;

    AAnimal *j = new ADog();
    j->makeSound();
    delete j;    

    return (0);
}