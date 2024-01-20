#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << " invalid pattern should be ./converter [arg] " << std::endl;
	}
	ScalarConverter a(av[1]);

	a.to_char();
	a.to_int();
	a.to_float();
	a.to_double();
}


