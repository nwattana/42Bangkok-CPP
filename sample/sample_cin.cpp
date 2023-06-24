#include <iostream>
#include <string>

int main()
{
	std::string myString;

	std::cout << "Test"<<std::endl;

	// cin
	std::cin >> myString;
	std::cout << "cin Line\n";
	std::cin.clear();
	std::cout << "My string : " << myString << std::endl;

}