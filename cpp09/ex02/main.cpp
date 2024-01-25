#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
	int i = 1;
	std::string str;
	std::stringstream ss;
	PmergeMe pm;
	double d=0;

	while (i < ac)
	{
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
		// std::cout << "In loop" << std::endl;
	}
	// pm.peek_front(5);
    // std::cout << "SORTED ++++ ++ +  " << std::endl;
	pm.peek_front(10);
    pm.sorted();
	pm.peek_front(10);

}