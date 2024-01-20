#include "ScalarConverter.hpp"

int main(int av, char **ac)
{
	if (av != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (1);
	}
	ScalarConverter sc(ac[1]);


	std::cout << sc;
	sc.convertToChar();
	sc.convertToInt();
	sc.convertToFloat();
	sc.convertToDouble();
}