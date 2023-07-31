#include <iostream>


int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "ADDRESS OF BRAIN: " << &brain << std::endl;
    std::cout << "ADDRESS held BY STRINGPTR : " << stringPTR << std::endl;
    std::cout << "ADDRESS held BY STRINGREF : " << &stringREF << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "VALUE OF BRAIN: " << brain << std::endl;
    std::cout << "VALUE POINTED TO BY STRINGPTR : " << *stringPTR << std::endl;
    std::cout << "VALUE POINTED TO BY STRINGREF : " << stringREF << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    return (0);
}