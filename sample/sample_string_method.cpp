#include <iostream>
#include <string>

int main(void)
{
	std::string input="";

	std::cin >> input;
	std::cout << input << std::endl;
	if (input.compare("EXIT") != 0) {
		std::cout << "EXIT was given" << std::endl;
	}
}
