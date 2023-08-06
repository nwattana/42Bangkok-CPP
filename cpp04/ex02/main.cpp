#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "AAnimal.hpp"
#include "Animal.hpp"


int main(void)
{
    // AAnimal * a1 = new AAnimal("Animal");

    // std::cout << "AAnimal type: " << a1->getType() << std::endl;
    // std::cout << "AAnimal make sound: ";
    // a1->makeSound();
    // delete a1;
    // std::cout << std::endl;

    Animal * a2 = new Animal("Animal");
    std::cout << "Animal type: " << a2->getType() << std::endl;
    std::cout << "Animal make sound: ";
    a2->makeSound();
    delete a2;
    std::cout << std::endl;
}