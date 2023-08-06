#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"


int main(void)
{
    {
    const Animal* meta = new Animal();
    const Animal* cat = new Dog();
    const Animal* dog = new Cat();
    std::cout << std::endl;
    std::cout << "Animal type: " << meta->getType() << std::endl;
    std::cout << "Animal make sound: \t\t";
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Dog make sound: \t\t";
    dog->makeSound();
    std::cout << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    std::cout << "Cat make sound: \t\t";
    cat->makeSound();
    std::cout << std::endl;

    delete meta;
    delete cat;
    delete dog;
    }
    // WrongAnimal * wd1 = new WrongDog();
    {
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* cat = new WrongDog();
    const WrongAnimal* dog = new WrongCat();
    std::cout << std::endl;
    std::cout << "WrongAnimal type: " << meta->getType() << std::endl;
    std::cout << "WrongAnimal make sound: \t\t";
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "WrongDog type: " << dog->getType() << std::endl;
    std::cout << "WrongDog make sound: \t\t";
    dog->makeSound();
    std::cout << std::endl;
    std::cout << "WrongCat type: " << cat->getType() << std::endl;
    std::cout << "WrongCat make sound: \t\t";
    cat->makeSound();
    std::cout << std::endl;

    delete meta;
    delete cat;
    delete dog;
    }
    {
        std::cout << std::endl;
        const WrongDog* wd1 = new WrongDog();
        std::cout << "WrongDog type: " << wd1->getType() << std::endl;
        std::cout << "WrongDog make sound: \t\t";
        wd1->makeSound();
        delete wd1;
        std::cout << std::endl;
        const WrongCat* wc1 = new WrongCat();
        std::cout << "WrongCat type: " << wc1->getType() << std::endl;
        std::cout << "WrongCat make sound: \t\t";
        wc1->makeSound();
        delete wc1;
        std::cout << std::endl;
    }
}