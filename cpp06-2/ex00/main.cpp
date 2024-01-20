#include "ScalarConverter.hpp"
#include <stdio.h>
int main(int av, char *ac[])
{
	if (av != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	std::string input = ac[1];
	int i = 0;
	int size = input.length();
	int space = 0;
	int count_char = 0;
	while (isspace(input[i]))
	{
		space++;
		i++;
	}
	while (!isspace(input[i]) && i < size)
	{
		count_char++;
		i++;
	}
	// Check if there is any space after the input and not end of string
	while (isspace(input[i]) && i < size)
	{
		space++;
		i++;
	}
	if (i != size)
	{
		// if user try to input like "42 42" or "aa bb cc" always return impossible
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (1);
	}
	std::string trim = input.substr(space, count_char);
	std::cout << "trim: " << trim << std::endl;

	ScarlarConverter ss(trim);
	return (0);
}

