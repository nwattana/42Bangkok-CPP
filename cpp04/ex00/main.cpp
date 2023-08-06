#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"


int main(void)
{
    {

    Dog * d1 = new Dog();
    std::cout << "Dog type: " << d1->getType() << std::endl;
    std::cout << "Dog make sound: ";
    d1->makeSound();
    delete d1;
    std::cout << std::endl;
    }
   { 
    Cat * c1 = new Cat();
    std::cout << "Cat type: " << c1->getType() << std::endl;
    std::cout << "Cat make sound: ";
    c1->makeSound();
    delete c1;
    std::cout << std::endl;
   } 
   {
    WrongDog * wd1 = new WrongDog();
    std::cout << "WrongDog type: " << wd1->getType() << std::endl;
    std::cout << "WrongDog make sound: ";
    wd1->makeSound();
    delete wd1;
    std::cout << std::endl;
   } 
    {  
    WrongCat * wc1 = new WrongCat();
    std::cout << "WrongCat type: " << wc1->getType() << std::endl;
    std::cout << "WrongCat make sound: ";
    wc1->makeSound();
    delete wc1;
    std::cout << std::endl;
    }
}