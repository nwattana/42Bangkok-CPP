#include "RPN.hpp"

int main(int ac, char *av[])
{
	std::string line;
	std::string::iterator it;
	std::string::iterator ite;
	RPN rpn;

	if (ac != 2)
	{
		std::cout << "Usage: ./RPN [expression]" << std::endl;
		return (1);
	}
	line = av[1];
	it = line.begin();
	ite = line.end();
	while (it != ite)
	{
		try
		{
			rpn.eval(*it);
		}
		catch (std::exception &e)
		{
			std::cout << "ERROR: " << e.what() << std::endl;
			return (1);
		}
		it++;
	}

	try
	{

		std::cout << rpn.getval() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}