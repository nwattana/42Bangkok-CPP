#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include "PmergeMe.hpp"

int isalldigit(char *s)
{
	if (!s)
	{
		return 0;
	}
	while (*s)
	{
		if (!::isdigit(*s))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

int main(int ac, char *av[])
{
	int i = 1;
	std::string str;
	std::stringstream ss;
	PmergeMe pm;
	double d=0;

	while (i < ac)
	{
		if (!isalldigit(av[i]))
		{
			std::cout << "Error: invalid input \"" << av[i] << "\" is Not Valid" << std::endl;
			return (1);
		}
		ss << std::string(av[i]);
		ss >> d;
		ss.clear();
		if (d > std::numeric_limits<int>::max() || d < 0)
		{
			std::cout << "Error: invalid input \"" << av[i] << "\" is Not Valid" << std::endl;
			return (1);
		}
		pm.push_back(d);
		i++;
	}
    pm.sorted();
	pm.report(5);

}