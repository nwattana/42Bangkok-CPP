#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    ///// My Test
    {
        int animalNum = 4;
        Animal *animals[animalNum];
        for (int i = 0; i < animalNum; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
            std::cout << std::endl;
            std::cout << std::endl;
        }

        std::cout << "==================  LOOP delete DOG CAT===============" << std::endl;
        for (int i = 0; i < animalNum; i++)
        {
            std::cout << "Animal type: " << animals[i]->getType() << std::endl;
            delete animals[i];
            std::cout << std::endl;
        }
        std::cout << "==================  LOOP delete DOG CAT END HERE===============" << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    {
        // copy constructor test header
        std::cout << "================== Copy constructor test ===============" << std::endl;
        Dog dog;
        dog.setBrain(0, "I am dog1");
        dog.getBrain();
        std::cout << std::endl;
        
        Dog dog2(dog);
        dog2.setBrain(1, "I am dog2");
        dog2.getBrain();
        std::cout << std::endl;

        Dog dog3 = dog2;
        dog3.setBrain(2, "I am dog3");
        dog3.getBrain();
        std::cout << std::endl;
    }
    std::cout << "==================  End Orthodox canonical Class test END HERE ===============" << std::endl;
    std::cout << std::endl
              << std::endl;
    return (0);
}