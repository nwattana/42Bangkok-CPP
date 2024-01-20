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


	// long double ld;

	// ld = static_cast<long double>(std::numeric_limits<float>::max());
	// std::cout << "ld: " << ld << std::endl;
	// ld = static_cast<long double>(12.0f);
	// std::cout << "ld: " << ld << std::endl;
	// ld = static_cast<long double>('a');
	// std::cout << "ld: " << ld << std::endl;
}