#include <iostream>
#include <string>

int main()
{
	std::string myString;
	std::cout << "Test"<<std::endl;

	// getline
	std::cout << "GET Line\n";
	std::getline(std::cin, myString);
	std::cout << myString;
}